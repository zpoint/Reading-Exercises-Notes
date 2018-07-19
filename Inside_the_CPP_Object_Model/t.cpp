#include <iostream>

struct a
{
		a()
		{
				std::cout << "class a" << std::endl;
		}
};

struct b
{
		b()
		{
				std::cout << "class b" << std::endl;
		}
};

struct c: public a, public b
{
		c(): c::b(), c::a() { }
};

int main()
{
		c cc;
		return 0;
}
