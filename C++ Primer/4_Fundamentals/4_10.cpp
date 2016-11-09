#include <iostream>

int main()
{
		int temp;
		std::cout << "Enter an integer, 42 to terminate:" << std::endl;
		while (1)
		{
				std::cin >> temp;
				if (std::cin.fail())
				{
						std::cout << "Invalid Input, Please enter an integer, 42 to terminate:" << std::endl;
						std::cin.clear();
						std::cin.ignore(BUFSIZ, '\n');
				}
				else if (temp == 42)
						break;
		}
		std::cout << "Get 42, terminate now" << std::endl;
		return(0);
}
