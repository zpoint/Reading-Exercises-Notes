#include "algostuff.hpp"

int main()
{
		std::vector<int> coll1;
		std::list<int> coll2;

		INSERT_ELEMENTS(coll1, 1, 9);
		PRINT_ELEMENTS(coll1, "coll1:     ");

		// square each element
		std::transform(coll1.cbegin(), coll1.cend(), coll1.cbegin(), coll1.begin(), std::multiplies<int>());
		PRINT_ELEMENTS(coll1, "squared:   ");

		// add each element traversed forward with each element traversed backward
		// and insert result into coll2
		std::transform(coll1.cbegin(), coll1.cend(), coll1.crbegin(), std::back_inserter(coll2), std::plus<int>());
		PRINT_ELEMENTS(coll2, "coll2:     ");

		// print differences of two corresponding elements
		std::cout << "diff:    ";
		std::transform(coll1.cbegin(), coll1.cend(), coll2.cbegin(), std::ostream_iterator<int>(std::cout, " "), std::minus<int>());
		std::cout << std::endl;

		return 0;
}
