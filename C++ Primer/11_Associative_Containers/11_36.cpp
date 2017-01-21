#include <iostream>
#include <string>

/*
 * Will throw a runtime error
 */

int main()
{
		std::string str(" ");
		std::cout << str.substr(1).size() << " " << str.substr(1) << std::endl;
		return 0;
}
