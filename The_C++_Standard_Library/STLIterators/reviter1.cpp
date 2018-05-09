#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

void print(int elem)
{
		std::cout << elem << ' ';
}

int main()
{
		// create list with elements from 1 to 9
		std::list<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		// print all elements in normal order
		std::for_each(coll.cbegin(), coll.cend(), print);
		std::cout << std::endl;

		// print all elements in reverse order
		std::for_each(coll.crbegin(), coll.crend(), print);
		std::cout << std::endl;

		/*
		 * reviter2
		 */
		std::vector<int> coll2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		std::vector<int>::const_iterator pos;
		pos = std::find(coll2.cbegin(), coll2.cend(), 5);

		std::cout << "pos: " << *pos << std::endl;

		std::vector<int>::const_reverse_iterator rpos(pos);
		std::cout << "rpos: " << *rpos << std::endl;


		return 0;
}
