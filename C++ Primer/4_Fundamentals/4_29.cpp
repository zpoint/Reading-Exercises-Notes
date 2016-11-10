#include <iostream>

int main()
{
		int x[10], *p = x;
		std::cout << sizeof(x)/sizeof(*x) << std::endl; // expected 10 * 4 / 4 = 10
		std::cout << sizeof(p)/sizeof(*p) << std::endl; // expected 8 / 4 = 2
		return(0);
}
