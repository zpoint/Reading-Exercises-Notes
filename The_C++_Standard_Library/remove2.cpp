#include <algorithm>
#include <iterator>
#include <list>
#include <iostream>

int main()
{
		std::list<int> coll;

		// insert elements from 6 to 1 and 1 to 6
		for (int i=1; i<=6; ++i)
		{
				coll.push_front(i);
				coll.push_back(i);
		}

		// print all elements of the collection
		std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		// remove all elements with value 3
		// - retain new end
		std::list<int>::iterator end = std::remove(coll.begin(), coll.end(), 3);

		// print resulting elements of the collection
		std::copy(coll.begin(), end, std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		// print number of removed elements
		std::cout << "number of removed elements: " << std::distance(end, coll.end()) << std::endl;

		// remove "removed" elements
		coll.erase(end, coll.end());

		// print all elements of the modified collection
		std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
		return 0;
}
