#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
		std::vector<int> ivec(10, 1);
		std::cout << std::count(ivec.cbegin(), ivec.cend(), 1) << std::endl;
		return 0;
}
