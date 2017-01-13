#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>

int main()
{
		std::multiset<std::string> c = {"abc", "def", "hij"};
		std::vector<std::string> v = {"lnm", "opq", "rst"};
		std::copy(v.begin(), v.end(), std::inserter(c, c.end()));
		for (const auto &i : c)
				std::cout << i << " ";
		std::cout << std::endl;
	
		/* Error, multiset has no member push_back	
		std::copy(v.begin(), v.end(), std::back_inserter(c));
		for (const auto &i : c)
				std::cout << i << " ";
		std::cout << std::endl;
		*/
		
		std::copy(c.begin(), c.end(), std::inserter(v, v.end()));
		for (const auto &i : v)
				std::cout << i << " ";
		std::cout << std::endl;

		std::copy(c.begin(), c.end(), std::back_inserter(v));
		for (const auto &i : v)
				std::cout << i << " ";
		std::cout << std::endl;
		return 0;
}
