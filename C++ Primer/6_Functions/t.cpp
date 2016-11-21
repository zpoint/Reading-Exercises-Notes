#include <iostream>

void fcn(const int i)
{
		std::cout << "const:" <<  i << std::endl;
}

void fcn(int *i)
{
		std::cout << i << std::endl;
}

void fcn(const int i, const int j)
{
		std::cout << i << " " << j << std::endl;
}

int main()
{
		int a = 3;
		fcn(1, 2);
		fcn(3);
		fcn(a);
		fcn(&a);
		return(0);
}
