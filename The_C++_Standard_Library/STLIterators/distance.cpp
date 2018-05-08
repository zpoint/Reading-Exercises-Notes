#include <iterator>
#include <iostream>
#include <list>
#include <algorithm>

int main()
{
		std::list<int> coll;

		// insert elements from -3 to 9
		for (int i = -3; i <= 9; ++i)
				coll.push_back(i);

		// search element with value 5
		std::list<int>::iterator pos;
		pos = std::find(coll.begin(), coll.end(), 5);

		if (pos != coll.end())
		{
				// process and print difference from the beginning
				std::cout << "difference between beginning and 5: " << std::distance(coll.begin(), pos) << std::endl;
		}
		else
				std::cout << "5 not found" << std::endl;

		return 0;
}
