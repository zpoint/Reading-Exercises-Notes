#include <iostream>
#include <string>
#include <limits>

class Parser 
{
		public:
			static int lookahead;
			
			Parser() 
			{
					lookahead = std::cin.peek();
			}

			void expr()
			{
					term();
					while (true)
					{
							if (lookahead == '+')
							{
									match('+'); term(); std::cout << "+";
							}
							else if (lookahead == '-')
							{
									match('-'); term(); std::cout << "-";
							}
							else if (lookahead == '\n')
							{
									std::cout << std::endl;
									match('\n');
							}
							else
							{
									term();
							}
					}
			}

			void term()
			{
					if (isdigit(static_cast<char>(lookahead)))
					{
							std::cout << static_cast<char>(lookahead); 
							match(lookahead);
					}
					else
							throw std::runtime_error("Syntax error");
			}

			void match(int i)
			{
					if (lookahead == i)
					{
							std::cin.get();
							lookahead = std::cin.peek();
					}
					else
							throw std::runtime_error("Syntax error");
			}
};

int Parser::lookahead;

class Postfix
{
		public:
			static void main(std::string args)
			{
					Parser parser = Parser();
					parser.expr();
					std::cout << std::endl;
			}
};

int main(int argc, char **argv)
{
		Postfix pfx;
		pfx.main(argv[0]);
		return 0;
}

