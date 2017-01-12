#include <map>
#include <string>
#include <iostream>
#include <utility>
#include <vector>

int main()
{
		std::vector<std::pair<std::string, std::string>> pair_vec;
		std::string children_name, birthday;
		while (std::cin >> children_name >> birthday)
				pair_vec.push_back(std::make_pair(children_name, birthday));
		for (const auto &i : pair_vec)
				std::cout << i.first << ": " << i.second << "\n";
		std::cout << std::endl;
		return 0;
}
