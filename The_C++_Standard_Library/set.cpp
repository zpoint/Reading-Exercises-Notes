#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

int main()
{
		// type of the collection:
		// - no duplicates
		// - elements are ingegral values
		// - descending order
		std::set<int, std::greater<int>> coll1;

		// insert elements in random oder using different member functions
		coll1.insert({ 4, 3, 5, 1, 6, 2});
		coll1.insert(5);

		// print all elements
		std::cout << "coll1: ";
		std::copy(coll1.cbegin(), coll1.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		// insert 4 again and process return value
		std::pair<std::set<int, std::greater<int>>::iterator, bool> status = coll1.insert(4);
		if (status.second)
				std::cout << "4 inserted as element "
						  << std::distance(coll1.cbegin(), status.first) + 1 << std::endl;
		else
				std::cout << "4 already exists" << std::endl;

		// assign elements to another set with ascending order
		std::set<int> coll2(coll1.cbegin(), coll1.cend());

		// print all elements of the copy using stream iterator
		std::cout << "coll2: ";
		std::copy(coll2.cbegin(), coll2.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		// remove all elements up to element with value 3
		coll2.erase(coll2.begin(), coll2.find(3));

		// remove all elements with value 5
		int num;
		num = coll2.erase(5);
		std::cout << num << " element(s) removed" << std::endl;

		// print all elements
		std::copy(coll2.cbegin(), coll2.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
		return 0;
}
