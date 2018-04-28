#include <vector>
#include <algorithm>
#include <iostream>

void print(int elem)
{
		std::cout << elem << ' ';
}

int main()
{
		std::vector<int> coll;

		// insert elements from 1 to 9
		for (int i=0; i<=9; ++i)
				coll.push_back(i);

		// print all elements
		std::for_each(coll.cbegin(), coll.cend(), print);
		std::cout << std::endl;
		return 0;
}
