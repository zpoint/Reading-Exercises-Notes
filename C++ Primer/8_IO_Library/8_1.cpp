#include <iostream>

std::istream& read(std::istream& is)
{
		std::cout << "\nCalling read" << std::endl;
		std::string s;
		while(is >> s)
				std::cout << s << "\n";
		is.clear();
		return is;
}

int main()
{
		read(std::cin);
		read(std::cin);
		return 0;
}
