#include "algostuff.hpp"

int main()
{
		std::vector<int> coll;

		INSERT_ELEMENTS(coll, 1, 9);

		// call print() for each element
		std::for_each(coll.cbegin(), coll.cend(), [] (int elem) { std::cout << elem << ' '; });
		std::cout << std::endl;

		// add 10 to each element
		std::for_each(coll.begin(), coll.end(), [] (int& elem) { elem += 10; });
		PRINT_ELEMENTS(coll);

		// add value of first element to each element
		std::for_each(coll.begin(), coll.end(), [=] (int& elem) { elem += *coll.begin(); });
		PRINT_ELEMENTS(coll);

		return 0;
}
