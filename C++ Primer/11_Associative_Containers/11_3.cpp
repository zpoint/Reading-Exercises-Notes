#include <map>
#include <string>
#include <iostream>

int main()
{
		std::map<std::string, std::size_t> str_map;
		std::string word;
		while (std::cin >> word)
				++str_map[word];
		for (const auto &w : str_map)
				std::cout << w.first << " occurs " << w.second << 
						((w.second > 1) ? " times" : " time") << "\n";
		std::cout << std::endl;
		return 0;
}
