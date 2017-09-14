#include <iostream>
#include <limits>

std::istream &is = std::cin;

void print(char c)
{
		std::cout << c;
}

char lookahead()
{
		return static_cast<char>(is.peek());
}

void match(char c)
{
		char temp;
		is.get(temp);
		if (temp != c)
				throw std::runtime_error("Match Error");
}

void term()
{
		char c = lookahead();
		if (isdigit(c))
		{
				match(c);
				print(c);
		}
		else
		{
				throw std::runtime_error("Syntax Error");
		}
}

void rest()
{
		if (lookahead() == '+')
		{
				match('+'); term(); print('+'); rest();
		}
		else if (lookahead() == '-')
		{
				match('-'); term(); print('-'); rest();
		}
		else if (lookahead() == ' ')
		{
				match(' '); rest(); 
		}
		else
		{
				// do nothing
		}
}

void expr()
{
		term(); rest();
}

int main()
{
		while (true)
		{
				std::cout << "Enter something, I will parse: " << std::endl;
				expr();
				std::cout << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
}
