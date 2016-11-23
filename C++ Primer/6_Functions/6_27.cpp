#include <iostream>

int sum(std::initializer_list<int> int_list)
{
		int sum;
		for (const auto i : int_list)
				sum += i;
		return sum;
}

int main()
{
		std::cout << "Calling sum(1, 2, 3, 4, 5 ,6)\n" << sum({1,2,3,4,5,6}) << std::endl;
		return 0;
}

