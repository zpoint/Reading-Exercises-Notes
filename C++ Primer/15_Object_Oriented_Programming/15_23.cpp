#include <iostream>

class Base
{
		public:
			virtual int fcn() { std::cout << "Base fcn" << std::endl; return 0; };
};

class D1 : public Base
{
		public:
			int fcn_(int) { std::cout << "D1 fcn_" << std::endl; return 0; };
			virtual void f2() { std::cout << "D1 f2" << std::endl; };
};

class D2 : public D1
{
		public:
			int fcn(int) { std::cout << "D2 fcn" << std::endl; return 0; };
			int fcn() { std::cout << "D2 fcn" << std::endl; return 0; }
			void f2() { std::cout << "D2 f2" << std::endl; } 
};

int main()
{
		return 0;
}
