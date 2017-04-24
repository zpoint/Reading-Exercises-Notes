#include <iostream>

template <typename T> void g(T&& val)
{
		std::cout << "In template, val: " << val << std::endl;
}

int main()
{
		int i = 0;
		const int ci = i;
		g(i); // T is int&
		g(ci); // T is int
		g(i * ci); // T is int
		return 0;
}
