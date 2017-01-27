#include <iostream>

int *b()    // type wrong 
{
		int *p = new int;
		*p = 22;
		return p;
}

int main()
{
		int *ptr_int = b();
		std::cout << ptr_int << " " << *ptr_int << std::endl;
		delete ptr_int;
		return 0;
}
