#include <iostream>

class Base
{
		public:
			virtual void f() {}
};

class Derived : public Base
{
		// yes
		void f() final override {}
};

int main()
{
		Derived d;
		return 0;
}
