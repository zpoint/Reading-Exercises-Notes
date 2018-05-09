#include <set>
#include <list>
#include <algorithm>
#include <iterator>
#include "../print.hpp"

int main()
{
		std::set<int> coll;

		// create insert iterator for coll
		// - inconvenient way
		std::insert_iterator<std::set<int>> iter(coll, coll.begin());

		// insert elements with the usual iterator interface
		*iter = 1;
		iter++;
		*iter = 2;
		iter++;
		*iter = 3;

		PRINT_ELEMENTS(coll, "set:  ");

		// create inserter and insert elements
		// - convenient way
		std::inserter(coll, coll.end()) = 44;
		std::inserter(coll, coll.end()) = 55;

		PRINT_ELEMENTS(coll, "set:  ");

		// use inserter to insert all elements into a list
		std::list<int> coll2;
		std::copy(coll.cbegin(), coll.cend(), std::inserter(coll2, coll2.begin()));

		PRINT_ELEMENTS(coll2, "list: ");

		// use inserter to reinsert all elements into the list before the second element
		std::copy(coll.cbegin(), coll.cend(), std::inserter(coll2, ++coll2.begin()));

		PRINT_ELEMENTS(coll2, "list: ");

		return 0;
}
