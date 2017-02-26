#include <iostream>

int global_int = 0;

class numbered {
		public:
				numbered(): mysn(++global_int) { std::cout << "constructor: " << global_int << std::endl; }
				numbered(const numbered &): mysn(++global_int) { std::cout << "copy constructor: " << global_int << std::endl; }
				numbered& operator=(const numbered &) { std::cout << "copy assign constructor: " << global_int << std::endl; }
				int mysn; 
};

void f (numbered s) { std::cout << s.mysn << std::endl; }

int main()
{
		numbered a, b = a, c = b;
		c = a;
		f(a); f(b); f(c);
		return 0;
}
