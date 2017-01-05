#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

int main()
{
		std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9}, ivec2, ivec4;
		std::list<int> lst;
		std::copy(ivec.begin(), ivec.end(), std::back_inserter(ivec2)); // same as ivec
		std::copy(ivec.begin(), ivec.end(), std::front_inserter(lst)); // reverse of ivec
		std::copy(ivec.begin(), ivec.end(), std::inserter(ivec4, ivec4.end())); // same as ivec

		std::cout << "ivec2(back_inserter): ";
		for (const auto &i : ivec2)
				std::cout << i << " ";
		std::cout << std::endl;
		std::cout << "lst(front_inserter): ";
		for (const auto &i : lst)
				std::cout << i << " ";
		std::cout << std::endl;
		std::cout << "ivec4: inserter(ivec4, ivec4.end())";
		for (const auto &i : ivec4)
				std::cout << i << " ";
		std::cout << std::endl;
		return 0;
}
