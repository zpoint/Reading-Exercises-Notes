#include <iostream>

struct Integral {
		operator const int() { std::cout << "Calling Const int" << std::endl; return 1; }
		operator int() const { std::cout << "calling int const" << std::endl; return 2; }
};

int main()
{
		const Integral ci;
		int cii = ci;
		Integral cij;
		int jj = cij;
		return 0;
}
