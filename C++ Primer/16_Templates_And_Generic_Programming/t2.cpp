#include <iostream>

void f(int v1, int& v2)
{
		std::cout << v1 << " " << ++v2 << std::endl;
}

void g(int& i)
{
		std::cout << i << std::endl;
}

template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2)
{
		// f(t2, t1);
		f(t1);
}

int main()
{
		int j = 3;
		flip(g, j, 42);
		return 0;
}
