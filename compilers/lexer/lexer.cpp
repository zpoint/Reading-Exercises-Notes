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
		Token() { /*std::cout << "Call default constructor of Token" << std::endl;*/ }
		Token(int t): tag(t) { }
		int tag = 0;
};

struct Tag
{
		static const int NUM = 256, ID = 257, TRUE = 258, FALSE = 259;
		const std::string operator[](const int num)
		{
				switch (num)
				{
						case NUM:
							return "NUM";
						case ID:
							return "ID";
						case TRUE:
							return "TRUE";
						case FALSE:
							return "FALSE";
						default:
							return "NOT A VALID TAG";
				}
		}
};


struct Num : Token
{
		Num(int v): Token(v), value(v) { }
	    int value;	
};

struct Word : Token
{
		std::string lexeme;
		Word(int t, std::string s): Token(t), lexeme(s) { }
		Word() { /* std::cout << "Call default constructor of Word" << std::endl;*/ }
};

struct Lexer
{
		public:
			int line = 1;
			Lexer();
			Token scan();
		private:
			char peek = ' ';
			bool comment_tag = false;
			int comment_type = 1; // 1 ==> // , 2 ==> /*
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
		while (comment_tag)
		{
				std::string str;
				std::cin.get(peek);
				str += peek;
				std::size_t size = str.size();
				if (peek == '\n' and comment_type == 1)
						comment_tag = false;
				else if (size >= 2 and str.substr(size - 2) == (comment_type == 1 ? "//" : "/*"))
						comment_tag = false;
		}
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
		if (peek == '/')
		{
				char next_char = std::cin.peek();
				if (next_char == '/')
				{
						comment_type = 1;
						comment_tag = true;
						std::cin.get(peek);
				}
				else if (next_char == '*')
				{
						comment_type = 2;
						comment_tag = true;
						std::cin.get(peek);
				}
		}
		Token t(peek);
		peek = ' ';
		return t;
}

int main()
{
		Lexer l;
		Tag tag;
		while (true)
		{
				Token t = l.scan();
				std::cout << tag[t.tag] << std::endl;
		}
}
