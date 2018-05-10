#include <iostream>
#include <list>
#include <algorithm>
#include "../print.hpp"

int main()
{
		std::list<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		PRINT_ELEMENTS(coll, "coll:         ");

		// remove third element
		std::list<int>::iterator pos;
		int count = 0; // call counter
		// Error, labmda object gets copied by remove_if(), the state gets duplicated
		// pos = std::remove_if(coll.begin(), coll.end(), [count] (int) mutable { return ++count == 3; });
		
		// Good, lambda objects internally used by remove_if() share the same state
		pos = std::remove_if(coll.begin(), coll.end(), [&count] (int) { return ++count == 3; });
		coll.erase(pos, coll.end());

		PRINT_ELEMENTS(coll, "3rd removed:  ");

		return 0;
}
