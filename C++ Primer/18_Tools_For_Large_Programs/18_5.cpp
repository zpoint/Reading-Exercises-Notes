#include <iostream>

int main()
{
		try
		{
				std::cout << "I am in try" << std::endl;
		}
		catch (...)
		{
				std::cout << "In any exception" << std::endl;
		}
		return 0;
}
