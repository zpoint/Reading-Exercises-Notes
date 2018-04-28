#include <set>
#include <algorithm>
#include <iterator>
#include <iostream>

int main()
{
		// unordered set with elements from 1 to 9
		std::set<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		// print all elements of the collection
		std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		// Remove all elements with value 3
		// - algorithm remove() does not work
		// - instead member function erase() works
		int num = coll.erase(3);

		// print number of removed elements
		std::cout << "number of removed elements: " << num << std::endl;

		// print all elements of the modified collection
		std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
		return 0;
}
