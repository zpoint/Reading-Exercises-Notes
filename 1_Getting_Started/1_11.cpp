#include <iostream>

int main()
{
		int max, min, i;
		std::cout << "Please enter two integers, I will print each number in the ranges sepcified by those integers" << std::endl;
		std::cin >> max >> min;
		if (max < min)
		{
				i = max;
				max = min;
				min = i;
		}
		i = min;
		while (i <= max)
				std::cout << i++ << std::endl;
		return 0;
}
