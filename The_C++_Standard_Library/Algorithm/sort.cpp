#include "algostuff.hpp"

int main()
{
		std::deque<int> coll;

		INSERT_ELEMENTS(coll, 1, 9);
		INSERT_ELEMENTS(coll, 1, 9);

		PRINT_ELEMENTS(coll, "on entry:    ");

		// sort elements
		std::sort(coll.begin(), coll.end());

		PRINT_ELEMENTS(coll, "sorted:      ");

		// sorted reverse
		std::sort(coll.begin(), coll.end(), std::greater<int>());
		PRINT_ELEMENTS(coll, "sorted >: ");

		return 0;
}
