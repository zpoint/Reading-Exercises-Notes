#include "algostuff.hpp"

int main()
{
		std::vector<int> coll = { 17, -3, 22, 13, 13, -9 };
		PRINT_ELEMENTS(coll, "coll:       ");

		// convert into relative values
		std::adjacent_difference(coll.cbegin(), coll.cend(), coll.begin());
		PRINT_ELEMENTS(coll, "relative:   ");

		// convert into absolute values
		std::partial_sum(coll.cbegin(), coll.cend(), coll.begin());
		PRINT_ELEMENTS(coll, "absolute:    ");

		return 0;
}
