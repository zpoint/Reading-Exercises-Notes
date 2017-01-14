#include <map>
#include <vector>
#include <string>
#include <utility>
#include <iostream>

int main()
{
		std::map<std::string, std::vector<int>> str_map{
				{"abc", {1, 2, 3}}};
		std::map<std::string, std::vector<int>>::value_type val("aa", {1, 2});
		std::pair<std::map<std::string, std::vector<int>>::iterator, bool> ret = str_map.insert(val);
		std::cout << ret.first->first << std::endl;
		return 0;
}

