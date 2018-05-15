#include "algostuff.hpp"

int main()
{
		std::set<int> coll;

		INSERT_ELEMENTS(coll, 1, 9);
		PRINT_ELEMENTS(coll);

		// print elements rotated one element to the left
		std::set<int>::const_iterator pos = std::next(coll.cbegin());
		std::rotate_copy(coll.cbegin(),
						 pos,
						 coll.cend(),
						 std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		// print elements rotated two elements to the right
		pos = coll.end();
		std::advance(pos, -2);
		std::rotate_copy(coll.cbegin(), pos, coll.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		// print elements rotated so that element with value 4 is the beginning
		std::rotate_copy(coll.cbegin(),
						 coll.find(4),
						 coll.cend(),
						 std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		return 0;
}
