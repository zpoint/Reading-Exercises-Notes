#include <iostream>
#include <map>
#include <string>

int main()
{
		std::map<int, std::string> is_map;
		is_map[0] = "abc";
		is_map[1] = "def";
		is_map[2] = "hij";
		for (auto &iter : is_map)
		{
				std::cout << "Before change: first: " << iter.first << " second: " << iter.second << "\n";
				iter.second = "ddd";
		}

		for (auto &iter : is_map)
				std::cout << "After change: first: " << iter.first << " second: " << iter.second << "\n";
		return 0;
}
