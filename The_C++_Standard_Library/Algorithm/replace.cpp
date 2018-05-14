#include "algostuff.hpp"

int main()
{
		std::list<int> coll;

		INSERT_ELEMENTS(coll, 2, 7);
		INSERT_ELEMENTS(coll, 4, 9);
		PRINT_ELEMENTS(coll, "coll:  ");

		// replace all elements with value 6 with value 42
		std::replace(coll.begin(), coll.end(), 
						6, // old value
						42);  // new value
		PRINT_ELEMENTS(coll, "coll:  ");

		// replace all elements with value less than 5 with 0
		std::replace_if(coll.begin(), 
						coll.end(), 
						[] (int elem) { return elem < 5; },
						0);
		PRINT_ELEMENTS(coll, "coll:  ");

		return 0;
}
