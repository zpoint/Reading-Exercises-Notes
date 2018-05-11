#include "algostuff.hpp"

void printCollection(const std::list<int>& l)
{
		PRINT_ELEMENTS(l);
}

bool lessForCollection(const std::list<int>& l1, const std::list<int>& l2)
{
		return std::lexicographical_compare(l1.begin(), l1.cend(), l2.cbegin(), l2.cend());
}

int main()
{
		std::list<int> c1, c2, c3, c4;

		// fill all collections with the same starting values
		INSERT_ELEMENTS(c1, 1, 5);
		c4 = c3 = c2 = c1;

		// and now some difference
		c1.push_back(7);
		c3.push_back(2);
		c3.push_back(0);
		c4.push_back(2);

		// create collection of collections
		std::vector<std::list<int>> cc;
		cc.insert(cc.begin(), { c1, c2, c3, c4, c3, c1, c4, c2 });

		// print all collections
		std::for_each(cc.cbegin(), cc.cend(), printCollection);
		std::cout << std::endl;

		// sort collection lexicographically
		std::sort(cc.begin(), cc.end(), lessForCollection);

		// print all collections again
		std::for_each(cc.cbegin(), cc.cend(), printCollection);

		return 0;
}
