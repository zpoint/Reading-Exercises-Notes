#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

bool isBigger(const std::string &str)
{
		return (str.size() >= 5) ? true : false;
}

int main()
{
		std::vector<std::string> str_vec = {"123", "444", "55666", "6546546", "3542435", "3423", "fdfds"};
		std::cout << "Before partition: " << std::endl;
		for (const auto &i : str_vec)
				std::cout << i << " ";
		std::cout << std::endl;

		partition(str_vec.begin(), str_vec.end(), isBigger);
		std::cout << "After partition: " << std::endl;
		for (const auto &i : str_vec)
				std::cout << i << " ";
		std::cout << std::endl;
		return 0;
}
