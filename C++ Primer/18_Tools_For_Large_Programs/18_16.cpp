#include <iostream>

namespace Exercise
{
		int ivar = 100;
		double dvar = 0;
		const int limit = 1000;
}

int ivar = 0;
// using namespace Exercise;
void manip()
{
		double dvar = 3.1416;
		// int iobj = limit + 1;
		++ivar;
		std::cout << "ivar: " << ivar << std::endl;
		++::ivar;
		std::cout << "::ivar: " << ::ivar << std::endl;
}

int main()
{
		manip();
		return 0;
}
