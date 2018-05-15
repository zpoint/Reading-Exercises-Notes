#include "algostuff.hpp"

int main()
{
		std::list<int> coll;

		INSERT_ELEMENTS(coll, 1, 9);
		INSERT_ELEMENTS(coll, 1, 9);
		coll.sort();
		PRINT_ELEMENTS(coll);

		// print first and last position 5 could get inserted
		std::pair<std::list<int>::const_iterator, std::list<int>::const_iterator> range;
		range = std::equal_range(coll.cbegin(), coll.cend(), 5);

		std::cout << "5 could get position "
				  << std::distance(coll.cbegin(), range.first) + 1
				  << " up to "
				  << std::distance(coll.cbegin(), range.second) + 1
				  << " without breaking the sorting" << std::endl;

		return 0;
}
