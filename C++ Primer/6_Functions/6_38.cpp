#include <iostream>

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

decltype(odd) &arrPtr(int i)
{
		int (&o)[5] = odd;
		int (&e)[5] = even;
		return (i % 2) ? o : e;
}

int main()
{
		std::cout << arrPtr(3) << std::endl;
		return 0;
}
