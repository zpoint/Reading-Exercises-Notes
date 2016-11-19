#include <iostream>

int main()
{
		double dval; int ival; int *pi;
		// illegal, dval = ival = pi = 0;
		 pi = 0;
		 dval = ival = 0;
		 std::cout << "pi: " << pi << " dval: " << dval << " ival: " << ival << std::endl;
		 return(0);
}
