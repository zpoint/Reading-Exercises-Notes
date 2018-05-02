#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>

template <typename T>
void PRINT_ELEMENTS(const T& CONTAINER, std::string val="")
{
		std::cout << val << ":\t";
		for (const auto &i : CONTAINER)
				std::cout << i << " ";
		std::cout << std::endl;
}

int main()
{
		std::deque<int> coll = { 1, 2, 3, 5, 7, 11, 13, 17, 19 };
		PRINT_ELEMENTS(coll);

		std::transform(coll.cbegin(), coll.cend(), coll.begin(), std::negate<int>());
		PRINT_ELEMENTS(coll, "negated");

		std::transform(coll.cbegin(), coll.cend(), coll.cbegin(), coll.begin(), std::multiplies<int>());
		PRINT_ELEMENTS(coll, "squared");
		return 0;
}
