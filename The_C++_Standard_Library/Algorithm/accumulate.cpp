#include "algostuff.hpp"

int main()
{
		std::vector<int> coll;

		INSERT_ELEMENTS(coll, 1, 9);
		PRINT_ELEMENTS(coll);

		// process sum of elements
		std::cout << "sum:    "
				  << std::accumulate(coll.cbegin(), coll.cend(), 0)
				  << std::endl;

		// process sum of elements less 100
		std::cout << "sum:    "
				  << std::accumulate(coll.cbegin(), coll.cend(), -100)
				  << std::endl;

		// process product of elements
		std::cout << "product: "
				  << std::accumulate(coll.cbegin(), coll.cend(), 1, std::multiplies<int>())
				  << std::endl;

		// process product of elements (use 0 as initial value)
		std::cout << "product: "
				  << std::accumulate(coll.cbegin(), coll.cend(), 0, std::multiplies<int>())
				  << std::endl;

		return 0;
}
