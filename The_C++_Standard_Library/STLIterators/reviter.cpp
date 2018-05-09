#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
		std::vector<int> coll;

		// insert elements from 1 to 9
		for (int i=1; i<=9; ++i)
				coll.push_back(i);

		// print all element in reverse order
		std::copy(coll.crbegin(), coll.crend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
		return 0;
}
