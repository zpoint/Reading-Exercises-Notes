#include "algostuff.hpp"

int main()
{
		std::vector<std::string> coll1 = { "Hello", "this", "is", "an", "example" };
		std::list<std::string> coll2;

		// copy elements of coll1 into coll2
		// - use back inserter to insert instead of overwrite
		std::copy(coll1.cbegin(), coll1.cend(), std::back_inserter(coll2));

		// print elements of coll2
		// - copy elements to cout using an ostream iterator
		std::copy(coll2.cbegin(), coll2.cend(), std::ostream_iterator<std::string>(std::cout, " "));
		std::cout << std::endl;

		// copy elements of coll1 into coll2 in reverse oder
		// - now overwriting
		std::copy(coll1.crbegin(), coll1.crend(), coll2.begin());

		// print elements of coll2 again
		std::copy(coll2.cbegin(), coll2.cend(), std::ostream_iterator<std::string>(std::cout, " "));
		std::cout << std::endl;

		return 0;
}
