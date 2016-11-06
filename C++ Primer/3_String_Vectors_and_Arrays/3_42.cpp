#include <iostream>
#include <vector>

int main()
{
		std::vector<int> ivec(10, 1);
		int arr[10];
		for (auto i = 0; i < 10; i++)
				arr[i] = ivec[i];
		for (auto i : arr)
				std::cout << i << " ";
		std::cout << std::endl;
		return(0);
}
