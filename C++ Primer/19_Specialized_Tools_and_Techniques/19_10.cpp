#include <iostream>
#include <typeinfo>

class A
{
		public:
			A() = default;
			virtual ~A() = default;
};

class B : public A
{
};

class C : public B
{
};

int main()
{
		A *pa = new C;
		std::cout << typeid(pa).name() << std::endl;
		C cobj;
		A &rb = cobj;
		std::cout << typeid(&rb).name() << std::endl;
		B *px = new B;
		A &ra = *px;
		std::cout << typeid(ra).name() << std::endl;
		return 0;
}
