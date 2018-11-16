#include <boost/phoenix/phoenix.hpp>
#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
		std::vector<int> v{1, 2, 3, 4, 5};

		using namespace boost::phoenix::placeholders;
		auto phoenix = arg1 > 2 && arg1 % 2 == 0;
		std::cout << std::count_if(v.begin(), v.end(), phoenix) << '\n';
		return 0;
}
