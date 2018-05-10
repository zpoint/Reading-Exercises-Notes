#include <functional>
#include <algorithm>
#include <numeric>
#include <map>
#include <string>
#include <iostream>

int main()
{
		std::map<std::string, int> coll;
		coll["a"] = 1;
		coll["b"] = 2;
		int sum = std::accumulate(coll.begin(), coll.end(), 0, std::bind(std::plus<int>(), std::placeholders::_1,
								std::bind(&std::map<std::string, int>::value_type::second, std::placeholders::_2)));
		std::cout << sum << std::endl;
		return 0;
}
