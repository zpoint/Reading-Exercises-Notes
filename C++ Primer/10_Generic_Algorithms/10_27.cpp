#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

int main()
{
		std::vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		for (const auto &i : ivec)
				std::cout << i << " ";
		std::cout << std::endl;
		std::list<int> lst;
		std::unique_copy(ivec.begin(), ivec.end(), std::inserter(lst, lst.begin()));
		for (const auto &i : lst)
				std::cout << i << " ";
		std::cout << std::endl;
		return 0;
}
