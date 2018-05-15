#include "algostuff.hpp"

int main()
{
		std::list<int> coll;
		INSERT_ELEMENTS(coll, 1, 9);
		INSERT_ELEMENTS(coll, 1, 9);
		coll.sort();
		PRINT_ELEMENTS(coll);

		// print first and last position 5 could get inserted
		std::list<int>::const_iterator pos1 = std::lower_bound(coll.cbegin(), coll.cend(), 5);
		std::list<int>::const_iterator pos2 = std::upper_bound(coll.cbegin(), coll.cend(), 5);

		std::cout << "5 could get position "
				  << std::distance(coll.cbegin(), pos1) + 1
				  << " up to "
				  << std::distance(coll.cbegin(), pos2) + 1
				  << " without breaking the sorting"
				  << std::endl;

		// insert 3 at the first possible position without breaking the sorting
		coll.insert(std::lower_bound(coll.begin(), coll.end(), 3), 3);

		// insert 7 at the last possible position without breaking the sorting
		coll.insert(std::upper_bound(coll.begin(), coll.end(), 7), 7);

		PRINT_ELEMENTS(coll);
		
		return 0;
}
