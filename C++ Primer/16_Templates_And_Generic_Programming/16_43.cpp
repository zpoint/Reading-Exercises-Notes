#include <iostream>

template <typename T> void g(T&& val)
{
		std::cout << "In template, val: " << val << std::endl;
		++val;
}

int main()
{
		int i = 0;
		const int ci = i;
		g(i = ci);
		std::cout << "i: " << i << std::endl;
		return 0;
}
