#include <iostream>
#include <string>
#include <vector>

int main()
{
		std::vector<std::string> vstr;
		std::string str;
		while (std::cin >> str && vstr.size() < 10)
				vstr.push_back(str);
		std::cout << "vstr.size(): " << vstr.size() << std::endl;
		return(0);
}
