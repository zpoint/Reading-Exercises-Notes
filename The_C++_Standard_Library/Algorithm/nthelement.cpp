#include "algostuff.hpp"

int main()
{
		std::deque<int> coll;

		INSERT_ELEMENTS(coll, 3, 7);
		INSERT_ELEMENTS(coll, 2, 6);
		INSERT_ELEMENTS(coll, 1, 5);
		PRINT_ELEMENTS(coll);

		// extract the four lowest elements
		std::nth_element(coll.begin(), coll.begin() + 3, coll.end());

		// print them
		std::cout << "the four lowest elements are:   ";
		std::copy(coll.cbegin(), coll.cbegin() + 4, std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		// extract the four highest elements
		std::nth_element(coll.begin(), coll.end() - 4, coll.end());

		// print them
		std::cout << "the four highest elements are: ";
		std::copy(coll.cend() - 4, coll.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		// extract the four highest elements (second version)
		std::nth_element(coll.begin(), coll.begin() + 3, coll.end(), std::greater<int>());

		// print them
		std::cout << "the four highest elements are: ";
		std::copy(coll.cbegin(), coll.cbegin() + 4, std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		return 0;
}
