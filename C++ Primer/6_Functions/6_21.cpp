#include <iostream>

int biggerInt(const int i, const int *b)
{
		if (i > *b)
				return i;
		return *b;
}

int main()
{
		int i, j;
		std::cout << "Enter two integers" << std::endl;
		std::cin >> i >> j;
		std::cout << "The bigger is " << biggerInt(i, &j) << std::endl;
		return 0;
}
