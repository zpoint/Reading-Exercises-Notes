#include "algostuff.hpp"

int main()
{
		std::vector<int> coll = { 5, 3, 9, 1, 3, 4, 8, 2, 6 };
		PRINT_ELEMENTS(coll, "coll: ");

		// define predicate: check wiehther element is odd
		auto isOdd = [] (int elem) { return elem % 2 == 1; };

		// check whether coll is partitioned in odd and even elements
		if (std::is_partitioned(coll.cbegin(), coll.cend(), isOdd))
		{
				std::cout << "coll is partitioned" << std::endl;

				// find first even element
				std::vector<int>::const_iterator pos = std::partition_point(coll.cbegin(), coll.cend(), isOdd);
				std::cout << "first even element: " << *pos << std::endl;
		}
		else
				std::cout << "coll is nnot partitioned" << std::endl;


        std::vector<int> coll2 = { 5, 3, 4, 8, 3 };
		PRINT_ELEMENTS(coll2, "coll2");
		std::vector<int>::const_iterator pos = std::partition_point(coll2.cbegin(), coll2.cend(), isOdd);
		std::cout << "first even element of coll2: " << *pos << std::endl;

		return 0;
}
