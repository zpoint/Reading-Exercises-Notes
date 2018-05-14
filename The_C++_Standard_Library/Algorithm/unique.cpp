#include "algostuff.hpp"

int main()
{
		// source data
		int source[] = { 1, 4, 4, 6, 1, 2, 2, 3, 1, 6, 6, 6, 5, 7, 5, 4, 4 };
		std::list<int> coll;

		// initialize coll with elements from source
		std::copy(std::begin(source), std::end(source), std::back_inserter(coll));
		PRINT_ELEMENTS(coll);

		// remove consecutive duplicates
		std::list<int>::iterator pos = std::unique(coll.begin(), coll.end());

		// print elements not removed
		// - use new logical end
		std::copy(coll.begin(), pos, std::ostream_iterator<int>(std::cout, " "));
		std::cout << "\n\n";

		// reinitialize coll with elements from source
		std::copy(std::begin(source), std::end(source), coll.begin());
		PRINT_ELEMENTS(coll);

		// remove elements if there was a previous greater element
		coll.erase(std::unique(coll.begin(), coll.end(), std::greater<int>()), coll.end());
		PRINT_ELEMENTS(coll);

		return 0;
}
