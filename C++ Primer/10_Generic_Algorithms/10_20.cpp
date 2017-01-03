#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
		std::vector<std::string> svec{"123", "1232353", "sfsdfgdsfd", "ghjghj"};
		auto count = std::count_if(svec.begin(), svec.end(), [](std::string &str) {return str.size() >= 6;});
		std::cout << count << std::endl;
		return 0;
}
