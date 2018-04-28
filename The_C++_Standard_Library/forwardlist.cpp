#include <forward_list>
#include <iostream>

int main()
{
		// create forward-list container for some prime numbers
		std::forward_list<long> coll = { 2, 3, 5, 7, 11, 13, 17 };

		// resize two times
		// - note: poor performance
		coll.resize(9);
		coll.resize(15, 99);

		// print all elements:
		for (long elem : coll)
				std::cout << elem << ' ';
		std::cout << std::endl;
		return 0;
}
