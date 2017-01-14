#include <map>
#include <string>
#include <iostream>

int main()
{
		std::map<std::string, std::size_t> word_count;
		std::string word;
		while (std::cin >> word)
				++word_count.insert({word, 0}).first->second;
		// word_count.insert() return a pair, pair.first in an iterator to word_count, the iterator itself is a pair, the iterator.second is the value
		for (const auto &w : word_count)
				std::cout << w.first << " " << w.second << std::endl; 
		return 0;
}
