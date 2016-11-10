#include <iostream>
struct test_struct
{
		int men[30];
};


int f()
{
		return(1);
}

int main()
{
		int x = 100, y = 100, a = 100, b = 100, i = 4;
		struct test_struct tmp, *p = &tmp;
		std::cout << "sizeof(x + y): " << sizeof (x + y) << std::endl;
		std::cout << "sizeof (a < b): " << sizeof (a < b) << std::endl;
		std::cout << "sizeof p->men[i]: " << sizeof p->men[i] << std::endl;
		std::cout << "sizeof f(): " << sizeof f() << std::endl;
		return(0);
}

