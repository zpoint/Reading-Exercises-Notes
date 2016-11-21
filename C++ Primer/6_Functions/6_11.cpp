#include <iostream>
#include <limits>

void exchange_by_reference(int &i1, int &i2)
{
		int tmp = i1;
		i1 = i2;
		i2 = tmp;
}

void get_int(int &i)
{
		while (!(std::cin >> i))
		{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Error Input, Please enter an integer!!!" << std::endl;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


int main()
{
		int i, j;
		std::cout << "Enter two integers, I will exchange them!" << std::endl;
		std::cout << "First Integer:" << std::endl;
		get_int(i);
		std::cout << "Second Integer:" << std::endl;
		get_int(j);
		std::cout << "Before swape, i: " << i << ", j: " << j << std::endl;
		exchange_by_reference(i, j);
		std::cout << "After swape, i: " << i << ", j: " << j << std::endl;
		return(0);
}
