#include <set>
#include <deque>
#include <algorithm>
#include <iterator>
#include <functional>
#include <iostream>

template <typename T>
void PRINT_ELEMENTS(const T& container, const std::string str = "")
{
		std::cout << str << ": ";
		for (const auto &i : container)
				std::cout << i << " ";
		std::cout << std::endl;
}

int main()
{
		std::set<int, std::greater<int>> coll1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		std::deque<int> coll2;

		// Note: due to the sorting criterion greate<>() elements have reverse order:
		PRINT_ELEMENTS(coll1, "initialized");

		// transform all elements into coll2 by multiplying them with 10
		std::transform(coll1.cbegin(), coll1.cend(),
						std::back_inserter(coll2), std::bind(std::multiplies<int>(), std::placeholders::_1, 10));
		PRINT_ELEMENTS(coll2, "transformed");

		// replace value equal to 70 with 42
		std::replace_if(coll2.begin(), coll2.end(), std::bind(std::equal_to<int>(), std::placeholders::_1, 70), 42);
		PRINT_ELEMENTS(coll2, "replaced");

		// remove all elements with values between 50 and 80
		coll2.erase(std::remove_if(coll2.begin(), coll2.end(), 
								std::bind(std::logical_and<bool>(),
										  std::bind(std::greater_equal<int>(), std::placeholders::_1, 50), 
										  std::bind(std::less_equal<int>(),    std::placeholders::_1, 80))),
					coll2.end());
		PRINT_ELEMENTS(coll2, "removed");
		return 0;
}
