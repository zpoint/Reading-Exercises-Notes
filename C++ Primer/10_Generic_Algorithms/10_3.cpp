#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
		std::vector<int> ivec(10, 1);
		std::cout << std::accumulate(ivec.cbegin(), ivec.cend(), 0) << std::endl;
		return 0;
}
