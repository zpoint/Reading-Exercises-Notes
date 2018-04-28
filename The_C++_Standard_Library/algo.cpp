#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
		// create vector with elements from 1 to 6 in arbitrary order
		std::vector<int> coll = { 2, 5, 4, 1, 6, 3 };

		// find and print minimum and maximum elements
		std::vector<int>::const_iterator minpos = std::min_element(coll.cbegin(), coll.cend());
		std::cout << "min: " << *minpos << std::endl;
		std::vector<int>::const_iterator maxpos = std::max_element(coll.cbegin(), coll.cend());
		std::cout << "max: " << *maxpos << std::endl;

		// sort all elements
		std::sort(coll.begin(), coll.end());

		// find the first element with value 3
		// - no cbegin()/cend() because later was modify the elements pos3 refers to
		std::vector<int>::iterator pos3 = std::find(coll.begin(), coll.end(), 3); // range value

		// reverse the order of the found element with value 3 and all following elements
		std::reverse(pos3, coll.end());

		// print all elements
		for (int elem : coll)
				std::cout << elem << std::endl;
		return 0;
}
