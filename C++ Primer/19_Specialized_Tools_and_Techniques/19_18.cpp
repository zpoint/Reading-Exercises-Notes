#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
		auto f = std::mem_fn(&std::string::empty);
		std::vector<std::string> svec = {"123", "456", ""};
		std::cout << std::count_if(svec.begin(), svec.end(), f) << std::endl;
		return 0;
}
