#include <iostream>
#include <vector>
/*
 * another way to do it in 7_44.cpp
 */

class NoDefault {
	public:
		NoDefault(int i = 3): n(i) { }
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

		std::vector<NoDefault> vec(10); // give it a default constructor
		return 0;
}
