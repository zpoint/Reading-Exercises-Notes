#include "algostuff.hpp"

bool differenceOne(int elem1, int elem2)
{
		return elem1 + 1 == elem2 || elem1 -1 == elem2;
}

int main()
{
		// source data
		int source[] = { 1, 4, 4, 6, 1, 2, 2, 3, 1, 6, 6, 6, 5, 7, 5, 4, 4 };

		// initialize coll with elements from source
		std::list<int> coll;
		std::copy(std::begin(source), std::end(source), std::back_inserter(coll));
		PRINT_ELEMENTS(coll);

		// print elements with consecutive duplicates removed
		std::unique_copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		// print elements without consecutive entries that differ by one
		std::unique_copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "), differenceOne);
		std::cout << std::endl;
		return 0;
}
