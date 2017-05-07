#include <iostream>

template <typename F, typename T1>
void flip(F f, T1 &&t1)
{
		// f(t2, t1);
		f(std::move(t1));
}

void g(int &&i, int& j)
{
		std::cout << i << " " << j << std::endl;
}

void h(int &&i)
{
		std::cout << i << std::endl;
}

int main()
{
		int i = 1;
		flip(h, i);
		return 0;
}

