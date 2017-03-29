#include <iostream>

template <typename T, unsigned N>
std::size_t size(const T (&)[N])
{
		return N;
}


int main()
{
		int arr[] = {1, 2, 3, 4};
		std::cout << size(arr) << std::endl;
		return 0;
}
