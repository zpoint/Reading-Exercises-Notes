#include "algostuff.hpp"

int main()
{
		std::list<int> coll;

		INSERT_ELEMENTS(coll, 1, 9);
		PRINT_ELEMENTS(coll);

		// check existence of element with value 5
		if (std::binary_search(coll.cbegin(), coll.cend(), 5))
				std::cout << "5 is present" << std::endl;
		else
				std::cout << "5 is not present" << std::endl;

		// check existence of element with value 42
		if (std::binary_search(coll.cbegin(), coll.cend(), 42))
				std::cout << "42 is present" << std::endl;
		else
				std::cout << "42 is not present" << std::endl;

		return 0;
}
