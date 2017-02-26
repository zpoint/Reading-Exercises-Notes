#include <iostream>

int global_int = 0;

class numbered {
		public:
				numbered(): mysn(++global_int) { std::cout << "constructor: " << global_int << std::endl; }
				numbered(const numbered &): mysn(++global_int) { std::cout << "copy constructor: " << global_int << std::endl; }
				int mysn;
};

void f (const numbered &s) { std::cout << s.mysn << std::endl; }

int main()
{
		numbered a, b = a, c = b;
		f(a); f(b); f(c);
		return 0;
}
