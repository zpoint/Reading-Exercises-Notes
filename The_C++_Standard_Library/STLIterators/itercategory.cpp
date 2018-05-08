#include <vector>
#include <iostream>

int main()
{
		std::vector<int> coll;

		// insert elements from -3 to 9
		for (int i = -3; i <= 9; ++i)
				coll.push_back(i);

		// print number of elements by processing the distance bwtween begining and end
		// - NOTE: use operator - for iterators
		std::cout << "number/distance: " << coll.end() - coll.begin() << std::endl;

		// print all elements
		// - NOTE: use operator < instead of operator !=
		std::vector<int>::iterator pos;
		for (pos = coll.begin(); pos < coll.end(); ++pos)
				std::cout << *pos << ' ';
		std::cout << std::endl;

		// print all elements
		// - NOTE: uses operator [] instead of operator *
		for (std::vector<int>::size_type i = 0; i < coll.size(); ++i)
			std::cout << coll.begin()[i] << ' ';
		std::cout << std::endl;	

		// print every second element
		// - NOTE: uses operator +=
		for (pos = coll.begin(); pos < coll.end() - 1; pos += 2)
				std::cout << *pos << ' ';
		std::cout << std::endl;

		return 0;
}
