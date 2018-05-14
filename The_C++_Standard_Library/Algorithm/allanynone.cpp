#include "algostuff.hpp"

int main()
{
		std::vector<int> coll;
		std::vector<int>::iterator pos;

		INSERT_ELEMENTS(coll, 1, 9);
		PRINT_ELEMENTS(coll, "coll: ");

		// define an object for the predicate (using a lambda)
		auto isEven = [] (int elem) { return elem % 2 == 0; };

		// print whether all, any, or none of the elements are/is even
		std::cout << std::boolalpha << "all even?:  "
				  << std::all_of(coll.cbegin(), coll.cend(), isEven) << std::endl;
		std::cout << "any even?: "
				  << std::any_of(coll.cbegin(), coll.cend(), isEven) << std::endl;
		std::cout << "none even?: "
				  << std::none_of(coll.cbegin(), coll.cend(), isEven) << std::endl;

		return 0;
}
