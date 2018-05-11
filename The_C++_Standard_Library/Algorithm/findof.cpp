#include "algostuff.hpp"

int main()
{
		std::vector<int> coll;
		std::list<int> searchcoll;

		INSERT_ELEMENTS(coll, 1, 11);
		INSERT_ELEMENTS(searchcoll, 3, 5);

		PRINT_ELEMENTS(coll,       "coll:       ");
		PRINT_ELEMENTS(searchcoll, "searchcoll: ");

		// search first occurence of an element of searchcoll in coll
		std::vector<int>::iterator pos;
		pos = std::find_first_of(coll.begin(), coll.end(), searchcoll.begin(), searchcoll.end());
		std::cout << "first element of searchcoll in coll is element "
				  << std::distance(coll.begin(), pos) + 1
				  << std::endl;

		// search last occurence of an element of searchcoll in coll
		std::vector<int>::reverse_iterator rpos;
		rpos = std::find_first_of(coll.rbegin(), coll.rend(), searchcoll.begin(), searchcoll.end());
		std::cout << "last element of searchcoll in coll is element "
				  << std::distance(coll.begin(), rpos.base())
				  << std::endl;

		return 0;
}
