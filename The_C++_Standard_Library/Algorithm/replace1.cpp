#include "algostuff.hpp"

int main()
{
		std::list<int> coll;

		INSERT_ELEMENTS(coll, 2, 6);
		INSERT_ELEMENTS(coll, 4, 9);
		PRINT_ELEMENTS(coll);

		// print all elements with value 5 replaced with 55
		std::replace_copy(coll.cbegin(), coll.cend(),
						std::ostream_iterator<int>(std::cout, " "),
						5,
						55);
		std::cout << std::endl;

		// print all elements with a value less than 5 replaced with 42
		std::replace_copy_if(coll.cbegin(), coll.cend(),
						std::ostream_iterator<int>(std::cout, " "),
						std::bind(std::less<int>(), std::placeholders::_1, 5),
						42);
		std::cout << std::endl;

		// print each element while each odd element is replaced with 0
		std::replace_copy_if(coll.cbegin(), coll.cend(),
							 std::ostream_iterator<int>(std::cout, " "),
							 [] (int elem) { return elem % 2 == 1; },
							 0);

		std::cout << std::endl;

		return 0;
}
