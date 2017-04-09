#include <iostream>

template <typename T> void f1(T, T)
{
		std::cout << "f1(T, T)" << std::endl;
}

template <typename T1, typename T2> void f2(T1, T2)
{
		std::cout << "f2(T1, T2)" << std::endl;
}

int main()
{
		int i = 0, j = 42, *p1 = &i, *p2 = &j;
		const int *cp1 = &i, *cp2 = &j;
		f1(p1, p2); // a
		f2(p1, p2); // b
		f1(cp1, cp2); // c
		f2(cp1, cp2); // d
		// f1(cp1, p1); // type mismatch
		f2(p1, cp1); // f
		return 0;
}
