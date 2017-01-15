#include <iostream>
#include <string>
#include <map>
#include <vector>

int main()
{
		std::map<std::string, std::vector<int>> str_map;
		std::map<std::string, std::vector<int>>::iterator iter = str_map.find("234");
		return 0;
}
