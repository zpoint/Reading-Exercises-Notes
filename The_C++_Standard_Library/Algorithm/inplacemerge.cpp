#include "algostuff.hpp"

int main()
{
		std::list<int> coll;

		// insert two sorted sequences
		INSERT_ELEMENTS(coll, 1, 7);
		INSERT_ELEMENTS(coll, 1, 8);
		PRINT_ELEMENTS(coll);

		// find beginning of second part (element after 7)
		std::list<int>::iterator pos;
		pos = std::find(coll.begin(), coll.end(), 7);
		++pos;

		// merge into one sorted range
		std::inplace_merge(coll.begin(), pos, coll.end());
		PRINT_ELEMENTS(coll);

		return 0;
}
