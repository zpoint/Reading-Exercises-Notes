#include <iostream>

int main()
{
		int sum = 0, val;
		std::cout << "Enter several integers, I will sum them" << std::endl;
		while (std::cin >> val)
				sum += val;
		std::cout << "Sum is " << sum << std::endl;
		return 0;
}
