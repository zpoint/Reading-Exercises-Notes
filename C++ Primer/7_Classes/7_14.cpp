#include <iostream>

struct test {
		int i = 1;
		int j = 2;
		test(int x): i(x) {};
};

int main()
{
		test t(5);
		std::cout << t.i << "\n" << t.j << std::endl;
		return 0;
}
