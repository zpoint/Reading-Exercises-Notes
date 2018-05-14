#include "algostuff.hpp"

int main()
{
		std::vector<int> coll1 = { 9, 8, 7, 7, 7, 5, 4, 2, 1 };
		std::vector<int> coll2 = { 5, 3, 2, 1, 4, 7, 9, 8, 6 };
		PRINT_ELEMENTS(coll1, "coll1:  ");
		PRINT_ELEMENTS(coll2, "coll2:  ");

		// check whether the collections are heaps
		std::cout << std::boolalpha << "coll1 is heap: "
				  << std::is_heap(coll1.cbegin(), coll1.cend()) << std::endl;
		std::cout << "coll2 is heap: "
				  << std::is_heap(coll2.cbegin(), coll2.cend()) << std::endl;

		// print the first element that is not a heap in coll2
		std::vector<int>::const_iterator pos = std::is_heap_until(coll2.cbegin(), coll2.cend());
		if (pos != coll2.end())
				std::cout << "fist non-heap element of coll2: " << *pos << std::endl;

		return 0;
}
