#include <iostream>
#include <string>

int main()
{
	std::string str1, str2;
	std::cout << "Enter two string, I will report which is less than other (EOF to terminate)" << std::endl;
	do
	{
		if (std::cin >> str1 >> str2)
			if (str1 < str2)
				std::cout << str1 << " is less than " << str2 << std::endl;
			else
				std::cout << str2 << " is less than " << str1 << std::endl;
	} while (std::cin);
	return(0);
}