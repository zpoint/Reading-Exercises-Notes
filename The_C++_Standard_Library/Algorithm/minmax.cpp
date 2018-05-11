#include <cstdlib>
#include "algostuff.hpp"

bool absLess(int elem1, int elem2)
{
		return abs(elem1) < abs(elem2);
}

int main()
{
		std::deque<int> coll;

		INSERT_ELEMENTS(coll, 2, 6);
		INSERT_ELEMENTS(coll, -3, 6);

		PRINT_ELEMENTS(coll);

		// process and print minimum and maximum
		std::cout << "minimum:  "
				  << *std::min_element(coll.cbegin(), coll.cend())
				  << std::endl;
		std::cout << "maximum:  "
				  << *std::max_element(coll.cbegin(), coll.cend())
				  << std::endl;

		// print min and max and their distance using minmax_element()
		auto mm = std::minmax_element(coll.cbegin(), coll.cend());
		std::cout << "min:      " << *mm.first << std::endl;
		std::cout << "max:      " << *mm.second << std::endl;
		std::cout << "distance: " << std::distance(mm.first, mm.second) << std::endl;

		// process and print minimum and maximum of absolute values
		std::cout << "minimum of absolute values: "
				  << *std::min_element(coll.cbegin(), coll.cend(), absLess)
				  << std::endl;
		std::cout << "maximum of absolute values: "
				  << *std::max_element(coll.cbegin(), coll.cend(), absLess)
				  << std::endl;

		return 0;
}
