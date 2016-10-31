#include <iostream>

int main()
{
		int p = 10, pp = 20, *ptr = &p;
		std::cout << "ptr: " << ptr << '\n' << std::endl;
		ptr = &pp;
		std::cout << "ptr: " << ptr << '\n' << std::endl;
		*ptr = 30;
		std::cout << "ptr: " << ptr << " pp: " << pp << '\n' << std::endl;
		return(0);
}
