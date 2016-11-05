#include <iostream>
#include <stddef.h>
#include <vector>
int main()
{
		int arr[10] = {};
		int arr2[10] = {};
		for (size_t i = 0; i < 10; i++)
				arr[i] = i;
		for (size_t i = 0; i < 10; i++)
				arr2[i] = arr[i];
		std::cout << "Array: ";
		for (auto &i : arr2)
				std::cout << i << " ";
		std::cout << std::endl;

		std::vector<int> vec1, vec2;
		for (size_t i = 0; i < 10; i++)
				vec1.push_back(i);
		vec2 = vec1;
		std::cout << "Vector: ";
		for (auto i : vec2)
				std::cout << i << " ";
		std::cout << std::endl;

		return(0);
}
