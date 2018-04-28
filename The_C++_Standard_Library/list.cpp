#include <iostream>
#include <list>

int main()
{
		std::list<char> coll; // list container for character elements

		// append elements from 'a' to 'z'
		for (char c='a'; c<='z'; ++c)
				coll.push_back(c);

		// print all elements:
		// - use range-based for loop
		for (char elem : coll)
				std::cout << elem << ' ';
		std::cout << std::endl;
		return 0;
}
