#include <iostream>

int main()
{
		int a = 3, b = 4;
		decltype(a) c = a; // int c
		decltype((b)) d = a; // int &d = a
		++c;
		std::cout << "After ++c: a: " << a << " b: " << b << " c: " << c << " d: " << d << std::endl;
		++d;
		std::cout << "After ++d: a: " << a << " b: " << b << " c: " << c << " d: " << d << std::endl;
		return(0);
}
