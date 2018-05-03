#include <iostream>
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>

template <typename T>
void PRINT_ELEMENTS(const T& CONTAINER, const std::string &val="")
{
		std::cout << val << ": ";
		for (const auto &i : CONTAINER)
				std::cout << i << " ";
		std::cout << std::endl;
}

int main()
{
	std::array<int, 10> a = { 11, 22, 33, 44 };
    PRINT_ELEMENTS(a);

	// modify last two elements
	a.back() = 9999999;
	a[a.size()-2] = 42;
	PRINT_ELEMENTS(a);

	// process sum of all elements
	std::cout << "sum: "
			  << std::accumulate(a.cbegin(), a.cend(), 0)
			  << std::endl;

	// negate all elements
	std::transform(a.cbegin(), a.cend(),
				   a.begin(),
				   std::negate<int>());
	PRINT_ELEMENTS(a);
	return 0;
}
