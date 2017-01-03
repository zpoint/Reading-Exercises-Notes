#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

bool check_size(const std::string str, std::size_t sz)
{
		return str.size() > sz;
}

void bigges(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
		sort(words.begin(), words.end());
		auto end_unique = unique(words.begin(), words.end());
		words.erase(end_unique, words.end());
		stable_sort(words.begin(), words.end(), [](const std::string &str1, const std::string &str2)
						{ return str1.size() < str2.size(); });
		auto wc = find_if(words.begin(), words.end(), std::bind(check_size, std::placeholders::_1, sz));
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
