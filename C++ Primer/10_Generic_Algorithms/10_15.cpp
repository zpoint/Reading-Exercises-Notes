#include <iostream>

int main()
{
		const int out = 3;
		auto f = [out](const int &k) {return out + k;};
		std::cout << f(5) << std::endl;
		return 0;
}
