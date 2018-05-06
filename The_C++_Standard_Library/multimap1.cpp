#include <map>
#include <string>
#include <iostream>
#include <iomanip>

int main()
{
		// create multimap as string/string dictionary
		std::multimap<std::string, std::string> dict;

		// insert some elements in random order
		dict.insert({ { "day", "Tag" }, { "strange", "fremd" },
					  { "car", "Auto" }, { "smart", "elegant" },
					  { "trait", "Merkmal" }, { "strange", "seltsam" },
					  { "smart", "raffiniert" }, { "smart", "klug" },
					  { "clever", "raffiniert" }
						});

		// print all elements
		std::cout.setf(std::ios::left, std::ios::adjustfield);
		std::cout << ' ' << std::setw(10) << "english " << "german " << std::endl;	
		std::cout << std::setfill('-') << std::setw(20) << "" << std::setfill(' ') << std::endl;
		for (const auto& elem : dict)
				std::cout << ' ' << std::setw(10) << elem.first << elem.second << std::endl;
		std::cout << std::endl;

		// print all values for key "smart"
		std::string word("smart");
		std::cout << word << ": " << std::endl;
		for (std::multimap<std::string, std::string>::iterator pos = dict.lower_bound(word);
						pos != dict.upper_bound(word);
						++pos)
		{
				std::cout << "    " << pos->second << std::endl;
		}

		// print all keys for value "raffiniert"
		word = ("raffiniert");
		std::cout << word << ": " << std::endl;
		for (const auto& elem : dict)
		{
				if (elem.second == word)
						std::cout << "   " << elem.first << std::endl;
		}
		return 0;
}
