#include <string>
#include <tuple>
#include <vector>
#include <iostream>


int main()
{
		std::string s = "sss";
		std::vector<std::string> svec = {"123", "456"};
		std::pair<std::string, int> m_pair = {s, 3};
		std::tuple<std::string, std::vector<std::string>, std::pair<std::string, int>> my_tuple{s, svec, m_pair};
		std::cout << std::get<0>(my_tuple) << std::endl;
		return 0;
}
