#include <iostream>
#include <string>
#include <map>

inline int char2int(char c)
{
		return c - (static_cast<int>('0') - 0);
}

inline bool isletter(char c)
{
		return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

inline bool isdigit(char c)
{
		return c >= '0' and c <= '9';
}

struct Token 
{
		Token() { throw std::runtime_error("Call default constructor of Token"); }
		Token(int t): tag(t) { }
		const int tag = 0;
};

struct Tag
{
		static const int NUM = 256, ID = 257, TRUE = 258, FALSE = 259;
};


struct Num : Token
{
		Num(int v): Token(v), value(v) { }
	    const int value;	
};

struct Word : Token
{
		const std::string lexeme;
		Word(int t, std::string s): Token(t), lexeme(s) { }
		Word() { throw std::runtime_error("Call default constructor of Word"); }
		Word& operator=(const Word &rhs)
		{
				if (tag != rhs.tag)
						throw std::runtime_error("Copy assignment operator, token mismatch");
				if (lexeme != rhs.lexeme)
						throw std::runtime_error("Copy assignment operator, lexeme mismatch");
				return *this;
		}
};

struct Lexer
{
		public:
			int line = 1;
			Lexer();
			Token scan();
		private:
			char peek = ' ';
			std::map<std::string, Word> words;
			void reserve(Word t) { words[t.lexeme] = t; }

};

Lexer::Lexer()
{
		reserve(Word(Tag::TRUE, "true"));
		reserve(Word(Tag::FALSE, "false"));
};

Token Lexer::scan()
{
		for ( ; ; std::cin.get(peek))
		{
				if (peek == ' ' || peek == '\t') continue;
				else if (peek == '\n') line += 1;
				else break;
		}
		if (isdigit(peek))
		{
				int v = 0;
				do
				{
						v = 10 * v + char2int(peek);
						std::cin.get(peek);
				}
				while (isdigit(peek));
				return Num(v);
		}
		if (isletter(peek))
		{
				std::string str;
				do
				{
						str += peek;
						std::cin.get(peek);
				}
				while (isdigit(peek) || isletter(peek));
				std::map<std::string, Word>::iterator iter = words.find(str);
				if (iter != words.end())
				{
						return (*iter).second;
				}
				
				else
				{
						Word new_word(Tag::ID, str);
						words[str] = new_word;
						return new_word;
				}
				
		}
		Token t(peek);
		peek = ' ';
		return t;
}

int main()
{
		Token t = Token('+');
}
