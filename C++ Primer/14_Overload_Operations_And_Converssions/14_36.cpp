#include <iostream>
#include <string>
#include <vector>

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
		std::vector<std::string> vec_str;
		PrString pr(std::cin);
		std::string buffer;
		while ((buffer = pr()) != "")
				vec_str.push_back(buffer);
		for (const auto &item : vec_str)
				std::cout << item << " ";
		std::cout << std::endl;
		return 0;
}
