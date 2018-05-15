#include "algostuff.hpp"

int main()
{
		std::list<int> coll1;
		std::set<int> coll2;

		// fill both collections with some sorted elements
		INSERT_ELEMENTS(coll1, 1, 6);
		INSERT_ELEMENTS(coll2, 3, 8);

		PRINT_ELEMENTS(coll1, "coll1:  ");
		PRINT_ELEMENTS(coll2, "coll2:  ");

		// print merged sequence
		std::cout << "merged:  ";
		std::merge(coll1.cbegin(), coll1.cend(), coll2.cbegin(), coll2.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		return 0;
}
