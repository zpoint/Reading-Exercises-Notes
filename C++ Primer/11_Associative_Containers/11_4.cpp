#include <map>
#include <set>
#include <string>
#include <iostream>

std::string pre_handle(std::string &str)
{
		for (std::size_t index = 0; index < str.size(); ++index)
		{
				if (std::isupper(str[index]))
						str[index] = std::tolower(str[index]);
				else if (std::ispunct(str[index]))
						str.erase(index--, 1); // index-- for erase
		}
		return str;
}

int main()
{
		std::map<std::string, std::size_t> str_map;
		std::string word;
		// store all string in lower case form in map
		while (std::cin >> word)
				++str_map[pre_handle(word)];
		for (const auto &w : str_map)
				std::cout << w.first << " occurs " << w.second << 
						((w.second > 1) ? " times" : " time") << "\n";
		std::cout << std::endl;
		return 0;
}
