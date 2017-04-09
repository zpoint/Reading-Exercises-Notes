#include <iostream>

template <typename T> T calc(T t, int)
{
		std::cout << "calc(T, int)" << std::endl;
		return t;
}

template <typename T> T fcn(T t, T)
{
		std::cout << "fcn(T, T)" << std::endl;
		return t;
}

int main()
{
		double d = 4.0;
		float f = 3.0;
		char c = 'c';
		calc(c, 'c'); // a
		calc(d, f); // b
		fcn(c, 'c'); // c
		fcn(d, 3.0); // d
		return 0;
}
