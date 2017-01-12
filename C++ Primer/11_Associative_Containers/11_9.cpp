#include <map>
#include <iostream>
#include <list>

int main()
{
		std::map<std::string, std::list<int>> word_map;
		std::list<int> lst{1, 2, 3};
		word_map["123"] = lst;
		for (const auto &i : word_map)
		{
				std::cout << "i.first: " << i.first << "\n";
				std::cout << "i.second: ";
				for (const auto &j : i.second)
						std::cout << j << " ";
				std::cout << std::endl;
		}
		std::cout << std::endl;
		return 0;
}
