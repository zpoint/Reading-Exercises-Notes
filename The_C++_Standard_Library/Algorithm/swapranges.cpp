#include "algostuff.hpp"

int main()
{
		std::vector<int> coll1;
		std::deque<int> coll2;

		INSERT_ELEMENTS(coll1, 1, 9);
		INSERT_ELEMENTS(coll2, 11, 23);
		PRINT_ELEMENTS(coll1, "coll1:  ");
		PRINT_ELEMENTS(coll2, "coll2:  ");

		// swap elements of coll1 with corresponding elements of coll2
		std::deque<int>::iterator pos;
		pos = std::swap_ranges(coll1.begin(), coll1.end(), coll2.begin());

		PRINT_ELEMENTS(coll1, "\ncoll1:   ");
		PRINT_ELEMENTS(coll2, "coll2:   ");
		if (pos != coll2.end())
				std::cout << "first element not modified: "
						  << *pos << std::endl;

		// mirror first three with last three elements in coll2
		std::swap_ranges(coll2.begin(), coll2.begin() + 3, coll2.rbegin());
		PRINT_ELEMENTS(coll2, "\ncoll2:    ");

		return 0;
}
