#include "algostuff.hpp"

bool bothEvenOrOdd(int elem1, int elem2)
{
		return elem1 % 2 == elem2 % 2;
}

int main()
{
		std::vector<int> coll1;
		std::list<int> coll2;
		std::deque<int> coll3;

		coll1 = { 1, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		coll2 = { 1, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
		coll3 = { 11, 12, 13, 19, 18, 17, 16, 15, 14, 11 };

		PRINT_ELEMENTS(coll1, "coll1: ");
		PRINT_ELEMENTS(coll2, "coll2: ");
		PRINT_ELEMENTS(coll3, "coll3: ");

		// check whether both collections have equal elements in any order
		if (std::is_permutation(coll1.cbegin(), coll1.cend(), coll2.cbegin()))
				std::cout << "coll1 and coll2 have equal elements" << std::endl;
		else
				std::cout << "coll1 and coll2 don't have equal elements" << std::endl;

		// check for corresponding number of even and odd elements
		if (std::is_permutation(coll1.cbegin(), coll1.cend(), coll3.cbegin(), bothEvenOrOdd))
				std::cout << "numbers of even and odd elements match" << std::endl;
		else
				std::cout << " number of even and odd elements don't match" << std::endl;

		PRINT_ELEMENTS(coll1, "coll1: ");
		PRINT_ELEMENTS(coll2, "coll2: ");
		PRINT_ELEMENTS(coll3, "coll3: ");

		return 0;
}
