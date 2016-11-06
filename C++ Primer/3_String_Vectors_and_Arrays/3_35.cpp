#include <iostream>

int main()
{
		int size;
		std::cout << "enter an integer for size of arr" << std::endl;
		std::cin >> size;
		int arr[size];
		for (auto &i : arr)
				i = 0;
		for (auto &i : arr)
				std::cout << i << " ";
		std::cout << std::endl;
		return(0);
}
