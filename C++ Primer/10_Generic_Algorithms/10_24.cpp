#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <iostream>
#include <functional>

bool compare(std::string &str, std::size_t sz)
{
		return sz > str.size();
}

int main()
{
		std::string word;
		std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		for (const auto &i : ivec)
				std::cout << i << " ";
		std::cout << std::endl << "Enter a word" << std::endl;

		std::cin >> word;
		auto iterator = std::find_if(ivec.begin(), ivec.end(), 
					std::bind(compare, word, std::placeholders::_1));
		if (iterator != ivec.end())
				std::cout << *iterator << std::endl;
		else
				std::cout << "No match" << std::endl;
}
