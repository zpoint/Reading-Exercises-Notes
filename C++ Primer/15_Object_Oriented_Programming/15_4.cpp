#include <iostream>

class Base {
};

// class Derived : public Derived { };

class Derived : private Base { };

class Derived2 : public Base { };

int main()
{
		Base b;
		return 0;
}
