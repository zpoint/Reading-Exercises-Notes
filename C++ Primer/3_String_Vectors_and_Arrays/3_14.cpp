#include <iostream>
#include <string>
#include <vector>

int main()
{
		std::vector<int> vint;
		int n1;
		while (std::cin >> n1)
				vint.push_back(n1);
		std::cout << "vint.size(): " << vint.size() << std::endl;
		return(0);
}
