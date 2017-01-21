#include <iostream>
#include <map>
#include <string>

void test(std::string str, std::map<std::string, std::string> str_map)
{
		str_map[str];
}

int main()
{
		std::map<std::string, std::string> str_map;
		const std::string a = "123";
		str_map[a];
}
