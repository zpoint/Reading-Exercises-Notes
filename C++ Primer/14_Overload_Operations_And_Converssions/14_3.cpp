#include <vector>
#include <string>
#include <iostream>

int main()
{
		std::vector<std::string> svec1(1, "123"), svec2(1, "456");
		std::cout << "a: " << ("cobble" == "stone") << std::endl; // unknown
		std::cout << "b: " << (svec1[0] == svec2[0]) << std::endl; // string ==
		std::cout << "c: " << (svec1 == svec2) << std::endl; // vector ==
		std::cout << "d: " << (svec1[0] == "stone") << std::endl; // string ==
		return 0;
}
