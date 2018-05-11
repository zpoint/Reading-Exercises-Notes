#include "algostuff.hpp"

// check whether an element is even or odd
bool checkEven (int elem, bool even)
{
		if (even)
				return elem % 2 == 0;
		else
				return elem % 2 == 1;
}

int main()
{
		std::vector<int > coll;

		INSERT_ELEMENTS(coll, 1, 9);
		PRINT_ELEMENTS(coll, "coll:  ");

		// arguments for checkEven()
		// -check for: "even odd even"
		bool checkEvenArgs[3] = { true, false, true };

		// search first subrange in coll
		std::vector<int>::iterator pos;
		pos = std::search(coll.begin(), coll.end(), checkEvenArgs, checkEvenArgs + 3, checkEven);

		// loop while subrange found
		while (pos != coll.end())
		{
				// print position of first element
				std::cout << "subrange found starting with element "
						  << std::distance(coll.begin(), pos) + 1
						  << std::endl;

				// search next subrange in coll
				pos = std::search(++pos, coll.end(), checkEvenArgs, checkEvenArgs + 3, checkEven);
		}
		return 0;
}
