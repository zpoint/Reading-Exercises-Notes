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

int main()
{
		MI mi;
}
