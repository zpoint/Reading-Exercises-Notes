#include "algostuff.hpp"

int main()
{
		std::list<int> coll1;

		INSERT_ELEMENTS(coll1, 1, 6);
		INSERT_ELEMENTS(coll1, 1, 9);
		PRINT_ELEMENTS(coll1);

		// print elements without those having the value 3
		std::remove_copy(coll1.cbegin(), coll1.cend(),
						 std::ostream_iterator<int>(std::cout, " "),
						 3);
		std::cout << std::endl;

		// print elements without those having a value greater than 4
		std::remove_copy_if(coll1.cbegin(), coll1.cend(),
						    std::ostream_iterator<int>(std::cout, " "),
							[] (int elem) { return elem > 4; });
		std::cout << std::endl;


		// copy all elements not less than 4 into a multiset
		std::multiset<int> coll2;
		std::remove_copy_if(coll1.cbegin(), coll1.cend(), std::inserter(coll2, coll2.end()), std::bind(std::less<int>(), std::placeholders::_1, 4));
		PRINT_ELEMENTS(coll2);

		return 0;
}
