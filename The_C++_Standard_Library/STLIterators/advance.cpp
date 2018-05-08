#include <iterator>
#include <iostream>
#include <list>
#include <algorithm>

int main()
{
		std::list<int> coll;

		// insert elements from 1 to 9
		for (int i = 1; i <= 9; ++i)
				coll.push_back(i);

		std::list<int>::iterator pos = coll.begin();

		// print actual element
		std::cout << *pos << std::endl;

		// step three elements forward
		std::advance(pos, 3);

		// print actual element
		std::cout << *pos << std::endl;

		// step one element backward
		std::advance(pos, -1);

		// print actual element
		std::cout << *pos << std::endl;
		return 0;
}
