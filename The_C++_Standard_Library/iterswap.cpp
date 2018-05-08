#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include "print.hpp"

int main()
{
		std::list<int> coll;

		// insert elements from 1 to 9
		for (int i = 0; i <= 9; ++i)
				coll.push_back(i);

		PRINT_ELEMENTS(coll);

		// swap first and second value
		std::iter_swap(coll.begin(), std::next(coll.begin()));

		PRINT_ELEMENTS(coll);

		// swap first and last value
		std::iter_swap(coll.begin(), std::prev(coll.end()));

		PRINT_ELEMENTS(coll);

		return 0;
}
