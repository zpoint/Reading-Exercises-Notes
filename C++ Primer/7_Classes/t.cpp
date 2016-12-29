#include <string>

class S {
	public:
		S(int i, int j): x(i), y(j) { };
		S() { }
		int x;
		int y;
};

class Nodefault {
		public:
				Nodefault(const std::string&){ }
};

Nodefault t = std::string("SSS");
Nodefault global_nd("SSS");

struct A {
		public:
				A(): my_mem(global_nd) { }
				Nodefault my_mem;
};

struct B {
		public:
				Nodefault b_menbers = std::string("b");
};

A a;

int main()
{
		S s(1, 2);
		B b;
		return 0;
}
