#include <iostream>
#include <string>

class PrString {
		public:
				PrString(std::istream &istream): is(istream) { }
				std::string operator()()
				{
						std::string line;
						std::getline(is, line);
						if (!is)
							return "";
						return line;
				}	
		private:
				std::istream &is;
};

int main()
{
		PrString pr(std::cin);
		std::cout << pr() << std::endl;
		return 0;
}
