#include <iterator>
#include <iostream>
#include <list>
#include <algorithm>

int main()
{
		// create list with elements from 1 to 9
		std::list<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		// find position of element with value 5
		std::list<int>::const_iterator pos;
		pos = std::find(coll.cbegin(), coll.cend(), 5);

		// print value of element
		std::cout << "*pos:    " << *pos << std::endl;

		// convert iterator to reverse iterator
		std::list<int>::const_reverse_iterator rpos(pos);

		// print value of the element to which the reverse itartor refers
		std::cout << "rpos:    " << *rpos << std::endl;

		// convert reverse itartor back to normal iterator
		std::list<int>::const_iterator rrpos;
		rrpos = rpos.base();

		// print value of the element to which the normal iterator refers
		std::cout << "rrpos:   " << *rrpos << std::endl;

		return 0;	
}
