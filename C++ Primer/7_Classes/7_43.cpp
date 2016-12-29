#include <iostream>

class NoDefault {
	public:
		NoDefault(int i): n(i) { }
		int n;
};

NoDefault global_nd(4);

class C {
	public:
		C(): nd(3) { } 
		NoDefault nd = global_nd;
};

int main()
{
		C c;
		std::cout << "c.nd.n: " << c.nd.n << std::endl;
		return 0;
}
