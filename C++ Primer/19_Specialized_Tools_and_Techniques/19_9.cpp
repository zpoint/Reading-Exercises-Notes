#include <iostream>
#include <typeinfo>

int main()
{
		int a;
		char c;
		std::cout << typeid(a).name() << std::endl;
		std::cout << typeid(c).name() << std::endl;
		return 0;
}
