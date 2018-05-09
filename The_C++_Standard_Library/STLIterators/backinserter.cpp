#include <vector>
#include <algorithm>
#include <iterator>
#include "../print.hpp"

int main()
{
		std::vector<int> coll;

		// create back inserter for coll
		// - inconvenient way
		std::back_insert_iterator<std::vector<int>> iter(coll);

		// insert elements with the usual iterator interface
		*iter = 1;
		iter++;
		*iter = 2;
		iter++;
		*iter = 3;
		PRINT_ELEMENTS(coll);

		// create back inserter and insert elements
		// - convenient way
		std::back_inserter(coll) = 44;
		std::back_inserter(coll) = 55;
		PRINT_ELEMENTS(coll);

		// use back inserter to append all elements again
		// - reserve enough memory to avoid reallocation
		coll.reserve(2 * coll.size());
		std::copy(coll.cbegin(), coll.cend(), std::back_inserter(coll));
		PRINT_ELEMENTS(coll);
		return 0;
}
