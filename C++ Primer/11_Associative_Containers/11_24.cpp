#include <map>
#include <iostream>

int main()
{
		std::map<int, int> m;
		m[0] = 1;
		for (const auto &i : m)
				std::cout << "first: " << i.first << " second: " << i.second << std::endl;
		return 0;
}
