#include "algostuff.hpp"

int main()
{
		std::vector<int> coll1;
		std::list<int> coll2;

		INSERT_ELEMENTS(coll1, 1, 9);
		PRINT_ELEMENTS(coll1, "coll1:     ");

		// negate all elements in coll1
		std::transform(coll1.cbegin(), coll1.cend(), coll1.begin(), std::negate<int>());
		PRINT_ELEMENTS(coll1, "negated:   ");

		// transform elements of coll1 into coll2 with ten times their value
		std::transform(coll1.cbegin(), coll1.cend(),
					   std::back_inserter(coll2), std::bind(std::multiplies<int>(), std::placeholders::_1, 10));
		PRINT_ELEMENTS(coll2, "coll2:      ");

		// print coll2 negatively and in reverse order
		std::transform(coll2.crbegin(), coll2.crend(), std::ostream_iterator<int>(std::cout, " "), [] (int elem) { return -elem; });
		std::cout << std::endl;

		return 0;
}
