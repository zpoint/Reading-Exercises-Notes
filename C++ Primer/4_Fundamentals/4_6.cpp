#include <iostream>

int main()
{
		int integer;
		std::cout << "Enter an integer: " << std::endl;
		while (!(std::cin >> integer)) // fail
		{
				std::cout << "Error input, Please enter an integer:" << std::endl;
				std::cin.clear();
				std::cin.ignore(BUFSIZ, '\n');
		}
		if (integer % 2 == 0)
				std::cout << integer << " is even" << std::endl;
		else
				std::cout << integer << " is odd" << std::endl;
		return(0);
}
