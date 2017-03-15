#include <functional>
#include <iostream>

int main()
{
		std::function<int(int, int)> f1 = [] (int i, int j) { return i + j; };
		std::cout << f1(1, 2) << std::endl;
		return 0;
}
