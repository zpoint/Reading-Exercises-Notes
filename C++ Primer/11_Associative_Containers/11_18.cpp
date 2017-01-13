#include <iostream>
#include <string>
#include <map>
#include <utilit>

int main()
{
		std::map<std::string, std::size_t> word_count;
		word_count["123"] = 3;
		std::map<std::string, std::size_t>::iterator map_it = word_count.begin();
		std::cout << map_it->first << " " << map_it->second << std::endl;
		return 0;
}
