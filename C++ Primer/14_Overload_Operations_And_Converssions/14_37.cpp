#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

class test {
		public:
				bool operator()(std::string &str1, std::string &str2) {return str1 < str2; }
};

int main()
{
		test t;
		std::vector<std::string> str_vec;
		std::string buffer;
		while (std::cin >> buffer)
				str_vec.push_back(buffer);
		std::sort(str_vec.begin(), str_vec.end(), t);
		for (const auto &item : str_vec)
				std::cout << item << " ";
		std::cout << std::endl;
		return 0;
}
