#include "algostuff.hpp"

int main()
{
		std::vector<int> coll1 = { 1, 2, 3, 4, 5, 6 };
		std::list<int>   coll2 = { 1, 2, 4, 8, 16, 3 };

		PRINT_ELEMENTS(coll1, "coll1:  ");
		PRINT_ELEMENTS(coll2, "coll2:  ");

		// find first mismatch
		auto values = std::mismatch(coll1.cbegin(), coll1.cend(), coll2.cbegin());
		if (values.first == coll1.end())
				std::cout << "no mismatch" << std::endl;
		else
				std::cout << "first mismatch: "
						  << *values.first << " and "
						  << *values.second << std::endl;

		// find first position where the element of coll1 is not 
		// less than the corresponding element of coll2
		values = std::mismatch(coll1.cbegin(), coll1.cend(),
						 	   coll2.cbegin(),
							   std::less_equal<int>());
		if (values.first == coll1.end())
				std::cout << "always less-or-equal" << std::endl;
		else
				std::cout << "not less-or-equal: "
						  << *values.first << " and " 
						  << *values.second << std::endl;

		return 0;
}
