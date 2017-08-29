#include <iostream>

struct Base
{
		void bar(int)
		{
				std::cout << "Base bar(int)" << std::endl;
		}
		protected:
			int ival;
};

struct Derived1 : virtual public Base
{
		void bar(char)
		{
				std::cout << "Derived1 bar(char)" << std::endl;
		}
		void foo(char)
		{
				std::cout << "Derived1 foo(char)" << std::endl;
		}
		protected:
			char cval;
};

struct Derived2 : virtual public Base
{
		void foo(int)
		{
				std::cout << "Derived2 foo(int)" << std::endl;
		}
		protected:
			int ival;
			char cval;
};

class VMI : public Derived1, public Derived2
{
};

int main()
{
		VMI vm;
		vm.Derived1::foo(1);
		vm.Derived2::foo(1);
		vm.bar(2);
		vm.Base::bar(2);
		return 0;
}
