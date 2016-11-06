#include <iostream>

int main()
{
		int arr[10] = {};
		for (auto i = 0; i < 10; i++)
				arr[i] = i + 1;
		int *p1 = arr, *p2 = arr + 5;
		p1 += p2 - p1;
		std::cout << *p1 << std::endl;
		return(0);
}
