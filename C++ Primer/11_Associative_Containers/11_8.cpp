#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
		std::vector<int> ivec;
		int i;
		while (std::cin >> i)
				ivec.push_back(i);
		// set don't need below operation
		std::sort(ivec.begin(), ivec.end());
		auto iter = std::unique(ivec.begin(), ivec.end());
		ivec.erase(iter, ivec.end());
		// done
		for (const auto &i : ivec)
				std::cout << i << " ";
		std::cout << std::endl;
		return 0;
}
