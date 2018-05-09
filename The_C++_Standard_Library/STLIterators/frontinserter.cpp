#include <list>
#include <algorithm>
#include <iterator>
#include "../print.hpp"

int main()
{
		std::list<int> coll;

		// create front inserter for coll
		// - inconvenient way
		std::front_insert_iterator<std::list<int>> iter(coll);

		// insert elements with the usual iterator interface
		*iter = 1;
		iter++;
		*iter = 2;
		iter++;
		*iter = 3;

		PRINT_ELEMENTS(coll);

		 // create front inserter and insert elements
		 // - convenient way
		std::front_inserter(coll) = 44;
		std::front_inserter(coll) = 55;

		PRINT_ELEMENTS(coll);

		// use front inserter to insert all elements again
		std::copy(coll.cbegin(), coll.cend(), std::front_inserter(coll));
		PRINT_ELEMENTS(coll);

		return 0;
}
