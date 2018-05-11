#include "algostuff.hpp"

int main()
{
		std::list<int> coll;
		INSERT_ELEMENTS(coll, 1, 9);
		INSERT_ELEMENTS(coll, 1, 9);

		PRINT_ELEMENTS(coll, "coll:  ");

		// find first element with value 4
		std::list<int>::iterator pos1;
		pos1 = std::find(coll.begin(), coll.end(), 4);

		// find second element with value 4
		std::list<int>::iterator pos2;
		if (pos1 != coll.end())
				pos2 = std::find(++pos1, coll.end(), 4);

		// print all element from first to second 4 (both included)
		// - note: now we need the position of the first 4 again (if any)
		if (pos1 != coll.end() and pos2 != coll.end())
				std::copy(--pos1, ++pos2, std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		return 0;
}
