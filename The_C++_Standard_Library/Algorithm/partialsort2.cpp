#include "algostuff.hpp"

int main()
{
		std::deque<int> coll1;
		std::vector<int> coll6(6); // initialize with 6 elements
		std::vector<int> coll30(30); // initialize with 30 elements

		INSERT_ELEMENTS(coll1, 3, 7);
		INSERT_ELEMENTS(coll1, 2, 6);
		INSERT_ELEMENTS(coll1, 1, 5);
		PRINT_ELEMENTS(coll1);

		// copy elements of coll1 sorted into coll6
		std::vector<int>::const_iterator pos6;
		pos6 = std::partial_sort_copy(coll1.cbegin(), coll1.cend(), coll6.begin(), coll6.end());
		
		// print all copied elements
		std::copy(coll6.cbegin(), pos6, std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		// copy elements of coll1 sorted into coll30
		std::vector<int>::const_iterator pos30;
		pos30 = std::partial_sort_copy(coll1.cbegin(), coll1.cend(), coll30.begin(), coll30.end(), std::greater<int>());

		// print all copied elements
		std::copy(coll30.cbegin(), pos30, std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		return 0;
}
