#include <iostream>
#include <string>


int main()
{
		std::string name("AnnaBelle");
		std::string numbers("0123456789");
		std::cout << numbers.find(name) << std::endl; // expect npos
		return 0;
}
