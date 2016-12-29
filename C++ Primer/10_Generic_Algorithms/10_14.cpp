#include <iostream>

int main()
{
		auto f = [](const int &i, const int &j) {return i + j;};
		std::cout << f(1, 3) << std::endl;
		return 0;
}
