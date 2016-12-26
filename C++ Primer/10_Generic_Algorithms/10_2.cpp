#include <iostream>
#include <algorithm>
#include <list>
#include <string>

int main()
{
		std::list<std::string> slist(10, "123");
		slist.push_back("456");
		std::cout << std::count(slist.cbegin(), slist.cend(), "456") << std::endl;
		return 0;
}
