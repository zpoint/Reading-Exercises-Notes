#include "algostuff.hpp"

int main()
{
		std::vector<int> coll1, coll2;

		INSERT_ELEMENTS(coll1, 1, 9);
		INSERT_ELEMENTS(coll2, 1, 9);
		PRINT_ELEMENTS(coll1, "coll1:    ");
		PRINT_ELEMENTS(coll2, "coll2:    ");
		std::cout << std::endl;

		// move all even elements to the front
		std::vector<int>::iterator pos1, pos2;
		pos1 = std::partition(coll1.begin(), coll1.end(), [] (int elem) { return elem % 2 == 0; });
		pos2 = std::stable_partition(coll2.begin(), coll2.end(), [] (int elem) { return elem % 2 == 0; });

		// print collections and first odd element
		PRINT_ELEMENTS(coll1, "coll1:     ");
		std::cout << "first odd element:  " << *pos1 << std::endl;
		PRINT_ELEMENTS(coll2, "coll2:     ");
		std::cout << "first odd element:  " << *pos2 << std::endl;

		return 0;
}
