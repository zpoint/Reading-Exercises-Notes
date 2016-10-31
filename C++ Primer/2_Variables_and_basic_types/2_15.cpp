#include <iostream>

int main()
{
		int ival = 1.01;
		// int &rval1 = 1.01 error, initializer must be an object
		int &rval1 = ival;
		// int &rval3 error, initializer must be an int object
		std::cout << "ival: " << ival << " rval1: " << rval1 << std::endl;
		return(0);
}
