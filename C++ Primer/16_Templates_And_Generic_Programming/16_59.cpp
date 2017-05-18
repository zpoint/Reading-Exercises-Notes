#include <vector>
#include <iostream>
#include <string>

int main()
{
		std::vector<std::string> svec;
		std::string s = "asda";
		svec.emplace_back(s);  // lvalue reference
		for (auto &item : svec)
				std::cout << item;
		std::cout << std::endl;
		return 0;
}
