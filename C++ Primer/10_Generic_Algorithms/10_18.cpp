#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void bigges(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
		sort(words.begin(), words.end());
		auto end_unique = unique(words.begin(), words.end());
		words.erase(end_unique, words.end());
		auto wc = partition(words.begin(), words.end(), 
						[sz](const std::string &str) { return str.size() <= sz;});
		auto count = words.end() - wc;
		std::cout << count << " elements longer than " << sz << std::endl;
		for_each(wc, words.end(),
						[](const std::string &s){std::cout << s << " ";});
		std::cout << std::endl;
}

int main()
{
		std::vector<std::string> svec;
		std::string words;
		while (std::cin >> words)
				svec.push_back(words);
		bigges(svec, 5);
		return 0;
}
