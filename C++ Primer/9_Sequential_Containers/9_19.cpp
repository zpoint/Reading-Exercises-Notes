#include <iostream>
#include <string>
#include <list>

int main()
{
		/*
		 * Just change deque to list
		 */
		std::string str;
		std::list<std::string> listr;
		while (std::cin >> str)
				listr.push_back(str);
		for (const auto i : listr)
				std::cout << i << " ";
		std::cout << std::endl;
		return 0;
}

