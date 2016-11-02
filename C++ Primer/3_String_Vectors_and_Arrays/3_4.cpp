#include <string>
#include <iostream>

int main()
{
		std::string str1, str2;
		std::cout << "Input two string: (seperate by \"new line\")" << std::endl;
		std::getline(std::cin, str1);
		std::getline(std::cin, str2);
		if (str1 == str2)
				std::cout << "Two input strings are equal" << std::endl;
		else if (str1 > str2)
				std::cout << str1 << " is larger" << std::endl;
		else
				std::cout << str2 << " is larger" << std::endl;

		// report whether string have same length
		if (str1.size() == str2.size())
				std::cout << "Two string have same length: " << str1.size() << std::endl;
		else if (str1.size() < str2.size())
				std::cout << str2 << " length: " << str2.size() << " is longer than " << str1.size() << std::endl;
		else
				std::cout << str1 << " length: " << str1.size() << " is longer than " << str2.size() << std::endl;
		return(0);
}
