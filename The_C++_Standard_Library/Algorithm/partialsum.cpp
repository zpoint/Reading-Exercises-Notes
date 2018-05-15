#include "algostuff.hpp"

int main()
{
		std::vector<int> coll;
		INSERT_ELEMENTS(coll, 1, 6);
		PRINT_ELEMENTS(coll);

		// print all partial sums
		std::partial_sum(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		// print all partial products
		std::partial_sum(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "), std::multiplies<int>());
		std::cout << std::endl;

		return 0;
}
