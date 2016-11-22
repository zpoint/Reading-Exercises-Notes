#include <iostream>

void printInt(const int *begin, const int *end)
{
		while (begin != end)
				std::cout << *begin++ << " ";
		std::cout << std::endl;
}

int main()
{
		int i = 0, j[2] = { 0, 1 };
		printInt(&i, &i + 1);
		printInt(std::begin(j), std::end(j));
		return 0;
}

