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
		Token(int t): tag(t) { }
		const int tag;
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
		reserve(Word(Tag.TRUE, "true"));
		reserve(Word(Tag.FALSE, "false"));
}

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
		if (isdigit(peek))
		{
				std::string str;
				do
				{
						str += peek;
						std::cin.get(peek);
				}
				while (isdigit(peek) || isletter(peek));
		}
}

int main()
{
		Token t = Token('+');
}
