#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool count_word(std::string &str, std::string::size_type sz)
{
		return str.size() <= sz;
}

int main()
{
		std::vector<std::string> svec;
		std::string word;
		while (std::cin >> word)
				svec.push_back(word);
		std::size_t count = std::count_if(svec.begin(), svec.end(), std::bind(count_word, std::placeholders::_1, 6));
		std::cout << count << std::endl;
		return 0;
}
