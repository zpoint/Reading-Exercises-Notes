#include <iostream>

template <typename T> void g(T val)
{
		std::cout << "In template(T val), val: " << val << std::endl;
		++val;
}

template <typename T> void g2(const T& val)
{
		std::cout << "Const T& val: " << val << std::endl;
}

int main()
{
		int i = 0;
		const int ci = i;
		g(i); // T is int
		g(ci); // T is int
		g(i * ci); // T is int

		g2(i); // int&
		g2(ci); // int&
		g2(i * ci); // int&
		return 0;
}
