#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
		// create ostream iterator for stream count
		// - value are sepearted by a newline character
		std::ostream_iterator<int> intWriter(std::cout, "\n");

		// write elements with the usual iterator interface
		*intWriter = 42;
		intWriter++;
		*intWriter = 77;
		intWriter++;
		*intWriter = -5;

		// create collection with elements from 1 to 9
		std::vector<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		// write all elements without any delimiter
		std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout));
		std::cout << std::endl;

		// write all element with " < " as delimiter
		std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " < "));
		std::cout << std::endl;
		return 0;
}
