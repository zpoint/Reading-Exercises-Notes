#include <iostream>

class A
{
		public:
		A() 
		{
				std::cout << "Constructor of class A" << std::endl;
		}
};

class B : public A
{
		public:
		B()
		{
				std::cout << "Default Constructor of class B : public A" << std::endl;
		}
};

class C : public B
{
		public:
		C()
		{
				std::cout << "Default Constructor of class C : public B" << std::endl;
		}
};

class X
{
		public:
		X()
		{
				std::cout << "Default Constructor of class X" << std::endl;
		}
};

class Y
{
		public:
		Y()
		{
				std::cout << "Default Constructor of class Y" << std::endl;
		}
};

class Z : public X, public Y
{
		public:
				Z()
				{
						std::cout << "Default Constructor of class Z : public X, public Y" << std::endl;
				}
};

class MI : public C, public Z
{
		public:
				MI()
				{
						std::cout << "Default Constructor of class MI : public C, public Z" << std::endl;
				}
};

class D : public X, public C 
{
		public:
			D()
			{
					std::cout << "Default Constructor of class D: public X, public C" << std::endl;
			}
};

int main()
{
		D *pd = new D;
		X *px = pd;
		A *pa = pd;
		B *pb = pd;
		C *pc = pd;
		return 0;
}
