#include <vector>
#include <string>
#include <iostream>

int main()
{
		std::string word;
		std::vector<std::string> vec;
		auto iter = vec.begin();
		while (std::cin >> word)
				iter = vec.insert(iter, word); // return first inserted element's iterator, assign to iter
		return 0;
}
