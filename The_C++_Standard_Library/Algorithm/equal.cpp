#include "algostuff.hpp"

bool bothEvenOrOdd(int elem1, int elem2)
{
		return elem1 % 2 == elem2 % 2;
}

int main()
{
		std::vector<int> coll1;
		std::list<int> coll2;

		INSERT_ELEMENTS(coll1, 1, 7);
		INSERT_ELEMENTS(coll2, 3, 9);

		PRINT_ELEMENTS(coll1, "coll1:  ");
		PRINT_ELEMENTS(coll2, "coll2:  ");

		// check whether both collections are equal
		if (std::equal(coll1.begin(), coll1.end(), coll2.begin()))
				std::cout << "coll1 == coll2" << std::endl;
		else
				std::cout << "coll1 != coll2" << std::endl;

		// check for corresponding even and odd elements
		if (std::equal(coll1.begin(), coll1.end(), coll2.begin(), bothEvenOrOdd))
				std::cout << "even and odd elements correspond" << std::endl;
		else
				std::cout << "even and odd elements do not correspond" << std::endl;

		return 0;
}
