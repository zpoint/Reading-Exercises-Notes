#include <iostream>
#include <utility>
#include <vector>
#include <string>

int main()
{
		std::vector<std::pair<std::string, int>> pair_vec;
		std::string word;
		int i;
		std::cout << "Enter: string int " << std::endl;
		while (std::cin >> word >> i)
				pair_vec.push_back(std::make_pair(word, i));
		return 0;
}
