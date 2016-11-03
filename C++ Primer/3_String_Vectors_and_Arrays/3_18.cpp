#include <iostream>
#include <vector>
#include <string>

int main()
{
		std::vector<int> ivec;
		// ivec[0] = 42; illegal, segment fault
		ivec.push_back(42);
		std::cout << ivec[0] << std::endl;
		return(0);
}
