#include <iostream>
#include <string>

// can only be used with class/type that can plus int

template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
		return *beg;
}

int main()
{
		std::string str = "fdsfdsfds";
		std::cout << fcn3(str.begin(), str.end()) << std::endl;
		return 0;
}
