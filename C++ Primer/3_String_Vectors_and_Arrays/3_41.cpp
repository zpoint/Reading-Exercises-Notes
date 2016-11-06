#include <iostream>
#include <vector>

int main()
{
		int arr[] = {1, 2, 3, 4, 5};
		std::vector<int> ivec(std::begin(arr), std::begin(arr) + 3);
		for (auto i : ivec)
				std::cout << i << " ";
		std::cout << std::endl;
		return(0);
}
