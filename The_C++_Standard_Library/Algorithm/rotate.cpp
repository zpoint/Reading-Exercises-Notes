#include "algostuff.hpp"

int main()
{
		std::vector<int> coll;

		INSERT_ELEMENTS(coll, 1, 9);
		PRINT_ELEMENTS(coll, "coll:       ");

		// rotate one element to the left
		std::vector<int>::iterator iter = std::rotate(
						coll.begin(), // beginning of range
						coll.begin() + 1, // new first element
						coll.end());  // end of range
		PRINT_ELEMENTS(coll, "one left:   ");

		// rotate two elements to the right
		std::rotate(coll.begin(),
					coll.end() - 2,
					coll.end());
		PRINT_ELEMENTS(coll, "two right:  ");

		// rotate so that element with value 4 is the beginning
		std::rotate(coll.begin(),
					std::find(coll.begin(), coll.end(), 4),
					coll.end());
		PRINT_ELEMENTS(coll, "4 first:    ");

		std::cout << "iter: " << *iter << std::endl;

		return 0;
}
