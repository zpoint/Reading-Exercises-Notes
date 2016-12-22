#include <iostream>
#include <string>
#include <deque>

int main()
{
		std::string str;
		std::deque<std::string> dqstr;
		while (std::cin >> str)
				dqstr.push_back(str);
		for (const auto i : dqstr)
				std::cout << i << " ";
		std::cout << std::endl;
		return 0;
}

