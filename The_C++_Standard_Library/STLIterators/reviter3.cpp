#include <iostream>
#include <iterator>
#include <deque>
#include <algorithm>

void print(int elem)
{
		std::cout << elem << ' ';
}

int main()
{
		// create deque with elements from 1 to 9
		std::deque<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		// find position of element with value 2
		std::deque<int>::const_iterator pos1;
		pos1 = std::find(coll.cbegin(), coll.cend(), 2);

		// find position of element with value 7
		std::deque<int>::const_iterator pos2;
		pos2 = std::find(coll.cbegin(), coll.cend(), 7);

		// print all elements in range [pos1, pos2)
		std::for_each(pos1, pos2, print);
		std::cout << std::endl;

		// convert iterators to reverse iterators
		std::deque<int>::const_reverse_iterator rpos1(pos1);
		std::deque<int>::const_reverse_iterator rpos2(pos2);

		// print all elements in range [pos1, pos2) in reverse order
		std::for_each(rpos2, rpos1, print);
		std::cout << std::endl;

		std::cout << *coll.rbegin() << std::endl;

		return 0;
}
