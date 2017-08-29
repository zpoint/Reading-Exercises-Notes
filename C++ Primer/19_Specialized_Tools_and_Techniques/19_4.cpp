#include <iostream>

class A {
 virtual void s() {};
};
class B : public A {};
class C : public B {};
class D : public B, public A {};

int main()
{
		// a
		A *pa = new C;
		// B *pb = dynamic_cast<B *>(pa);
		
		B *pb = new B;
		// C *pc = dynamic_cast<C *>(pb);
		// A pa = new D;
		// B *pb = dynamic_cast<B *>(pa);
		try
		{
				C& pc = dynamic_cast<C&>(*pa);
		}
		catch (std::bad_alloc e)
		{
				std::cout << e.what() << std::endl;
		}
		return 0;
}
