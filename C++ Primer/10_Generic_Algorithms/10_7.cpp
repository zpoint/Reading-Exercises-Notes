#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

int main()
{
		std::vector<int> vec;
		std::list<int> lst;
		int i;
		while (std::cin >> i)
				lst.push_back(i);
		vec.resize(lst.size()); // necessary
		copy(lst.cbegin(), lst.cend(), vec.begin());
		for (const auto i : vec)
				std::cout << i << " ";
		std::cout << std::endl;
		
		// b
		std::vector<int> vec2;
		vec2.resize(10);
		fill_n(vec2.begin(), 10, 0);

		for (const auto i : vec2)
				std::cout << i << " ";
		std::cout << std::endl;
		
		return 0;
}
