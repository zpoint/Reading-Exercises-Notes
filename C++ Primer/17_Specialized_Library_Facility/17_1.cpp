#include <iostream>
#include <tuple>

int main()
{
		std::tuple<int, int, int> it3{10, 20, 30};
		std::cout << std::get<0>(it3) << std::endl;
		return 0;
}
