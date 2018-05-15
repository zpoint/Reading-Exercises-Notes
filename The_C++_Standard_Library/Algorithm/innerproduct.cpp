#include "algostuff.hpp"

int main()
{
		std::list<int> coll;

		INSERT_ELEMENTS(coll, 1, 6);
		PRINT_ELEMENTS(coll);

		// process sum of all products
		// (0 + 1*1 + 2*2 + 3*3 + 4*4 +5*5 + 6*6)
		std::cout << "inner_product: "
				  << std::inner_product(coll.cbegin(), coll.cend(), coll.cbegin(), 0)
				  << std::endl;

		// process sum of 1*6 ... 6*1
		std::cout << "inner reverse product: "
				  << std::inner_product(coll.cbegin(), coll.cend(), coll.crbegin(), 0)
				  << std::endl;

		// process product of all sum
		// (1 * 1+1 * 2+2 * 3+3 * 4+4 * 5+5 * 6+6)
		std::cout << "product of sums: "
				  << std::inner_product(coll.cbegin(), coll.cend(), coll.cbegin(),
								  	    1,
										std::multiplies<int>(),
										std::plus<int>())
				  << std::endl;

		return 0;
}
