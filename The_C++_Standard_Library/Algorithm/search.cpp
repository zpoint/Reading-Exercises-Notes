#include "algostuff.hpp"

int main()
{
		std::deque<int> coll;
		std::list<int> subcoll;

		INSERT_ELEMENTS(coll, 1, 7);
		INSERT_ELEMENTS(coll, 1, 7);
		INSERT_ELEMENTS(subcoll, 3, 6);

		PRINT_ELEMENTS(coll,    "coll:      ");
		PRINT_ELEMENTS(subcoll, "subcoll:   ");

		// search first occurence of subcoll in coll
		std::deque<int>::iterator pos;
		pos = std::search(coll.begin(), coll.end(), subcoll.begin(), subcoll.end());

		while (pos != coll.end())
		{
				// print position of first element
				std::cout << "subcoll found starting with element "
						  << std::distance(coll.begin(), pos) + 1
						  << std::endl;

				// search next occurence of subcoll
				++pos;
				pos = std::search(pos, coll.end(),
								  subcoll.begin(), subcoll.end());
		}

		return 0;
}
