#include <iostream>

int main()
{
		std::size_t v1 = 42;
		auto f = [v1] () mutable {return ++v1;};
		v1 = 0;
		auto j = f();
		std::cout << j << std::endl;
		std::cout << v1 << std::endl;
		auto k = f();
		std::cout << k << std::endl;
		std::cout << v1 << std::endl;
}
