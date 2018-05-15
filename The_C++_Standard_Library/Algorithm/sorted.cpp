#include "algostuff.hpp"

int main()
{
		std::vector<int> c1 = { 1, 2, 2, 4, 6, 7, 7, 9 };
		std::deque<int> c2 = { 2, 2, 2, 3, 6, 6, 8, 9 };

		// print source ranges
		std::cout << "c1:                          ";
		std::copy(c1.cbegin(), c1.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
		std::cout << "c2:                          ";
		std::copy(c2.cbegin(), c2.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << '\n' << std::endl;

		// sum the ranges by using merge()
		std::cout << "merge():                     ";
		std::merge(c1.cbegin(), c1.cend(), c2.cbegin(), c2.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		// write the ranges by using set_union()
		std::cout << "set_union():                 ";
		std::set_union(c1.cbegin(), c1.cend(), c2.cbegin(), c2.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		// intersect the ranges by using set_intersection()
		std::cout << "set_intersection():          ";
		std::set_intersection(c1.cbegin(), c1.cend(), c2.cbegin(), c2.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		// determine elements of first range without elements of second range
		// by using set_difference()
		std::cout << "set_difference():            ";
		std::set_difference(c1.cbegin(), c1.cend(), c2.cbegin(), c2.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		// determine difference the ranges with set_symmetric_difference()
		std::cout << "set_symmetric_difference():  ";
		std::set_symmetric_difference(c1.cbegin(), c1.cend(), c2.cbegin(), c2.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;

		return 0;
}
