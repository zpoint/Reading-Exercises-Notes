#include <iostream>
#include <string>
#include <map>

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
		int tmp;
		for ( ; ; std::cin.get(tmp))
		{
				peek = static_cast<char>(tmp);
				if (peek = ' ' || peek == '\t') continue;
				else if (peek == '\n') line += 1;
				else break;
		}
		if isdigit(peek)
		{
				int v = 0;
				do
				{
						v = 
				}
		}
}

int main()
{
		Token t = Token('+');
}
