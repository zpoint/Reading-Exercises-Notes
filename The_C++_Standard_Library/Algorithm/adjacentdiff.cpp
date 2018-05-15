#include "algostuff.hpp"

int main()
{
		std::deque<int> coll;

		INSERT_ELEMENTS(coll, 1, 6);
		PRINT_ELEMENTS(coll);

		// print all differences between elements
		std::adjacent_difference(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		// print all sums with the predecessors
		std::adjacent_difference(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "), std::plus<int>());
		std::cout << std::endl;

		// print all products between elements
		std::adjacent_difference(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "), std::multiplies<int>());
		std::cout << std::endl;

		return 0;
}
