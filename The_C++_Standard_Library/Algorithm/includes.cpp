#include "algostuff.hpp"

int main()
{
		std::list<int> coll;
		std::vector<int> search;

		INSERT_ELEMENTS(coll, 1, 9);
		PRINT_ELEMENTS(coll,   "coll:      ");

		search.push_back(3);
		search.push_back(4);
		search.push_back(7);
		PRINT_ELEMENTS(search, "search:    ");

		// check whether all elements in search are also in coll
		if (std::includes(coll.cbegin(), coll.cend(), search.cbegin(), search.cend()))
				std::cout << "all elements of search are also in coll" << std::endl;
		else
				std::cout << "not all elements of search are also in coll" << std::endl;

		return 0;
}
