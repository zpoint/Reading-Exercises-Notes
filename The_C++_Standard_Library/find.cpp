#include <algorithm>
#include <list>
#include <iostream>

int main()
{
		std::list<int> coll;
		// insert elements from 20 to 40
		for (int i=20; i<=40; ++i)
				coll.push_back(i);

		// find position of element with value 3
		// - there is none, so pos3 get coll.end()
		std::list<int>::iterator pos3 = std::find(coll.begin(), coll.end(), 3); // range value

		// reverse the order of elements bwtween found element and the end
		// - because pos3 in coll.end() it recerses an empty range
		std::reverse(pos3, coll.end());

		// find positions of value 25 and 35
		std::list<int>::iterator pos25, pos35;
		pos25 = std::find(coll.begin(), coll.end(), 25); // range value
		pos35 = std::find(coll.begin(), coll.end(), 35); // range value

		// print the maximum of the corresponding range
		// - note: including pos25 but excluding pos35
		std::cout << "max: " << *std::max_element(pos25, pos35) << std::endl;

		// process the elements including the last position
		std::cout << "max: " << *max_element(pos25, ++pos35) << std::endl;
		return 0;
}
