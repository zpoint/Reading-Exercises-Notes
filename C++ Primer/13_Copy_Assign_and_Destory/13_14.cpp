#include <iostream>

int global_int = 0;

class numbered {
		public:
				numbered(): mysn(++global_int) { }
				int mysn;
};

void f (numbered s) { std::cout << s.mysn << std::endl; }

int main()
{
		numbered a, b = a, c = b;
		f(a); f(b); f(c);
		return 0;
}
