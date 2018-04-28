#include <algorithm>
#include <iterator>
#include <list>
#include <iostream>

int main()
{
		std::list<int> coll;

		// insert element from 6 to 1 and 1 to 6
		for (int i=1; i<=6; ++i)
		{
				coll.push_front(i);
				coll.push_back(i);
		}

		// print all elements of the collection
		std::cout << "pre:  ";
		std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		// remove all elements with value 3
		std::remove(coll.begin(), coll.end(), 3);

		// print a;; elements of the collection
		std::cout << "post: ";
		std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
		return 0;
}
