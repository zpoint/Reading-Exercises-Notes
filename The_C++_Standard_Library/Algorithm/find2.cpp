#include "algostuff.hpp"

int main()
{
		std::vector<int> coll;
		std::vector<int>::iterator pos;

		INSERT_ELEMENTS(coll, 1, 9);
		PRINT_ELEMENTS(coll, "coll:  ");

		// find first element greater than 3
		pos = std::find_if(coll.begin(), coll.end(), std::bind(std::greater<int>(), std::placeholders::_1, 3));

		// print its position
		std::cout << "the "
				  << std::distance(coll.begin(), pos) + 1
				  << ". element is the first greater than 3" << std::endl;

		// find first element divisible by 3
		pos = std::find_if(coll.begin(), coll.end(), [] (int elem) { return elem % 3 == 0; });

		// print its position
		std::cout << "the "
				  << std::distance(coll.begin(), pos) + 1
				  << ". element is the first divisible by 3" << std::endl;

		// find first element not < 5
		pos = std::find_if_not(coll.begin(), coll.end(), std::bind(std::less<int>(), std::placeholders::_1, 5));
		std::cout << "first value >=5:  " << *pos << std::endl;
		return 0;
}
