#include <iostream>

int main()
{
		int i = 0, &r1 = i; double d = 0, &r2 = d;
		std::cout << "Initialized: i: " << i << " r1: " << r1 << " d: " << d << " r2: " << r2 << "\n" << std::endl; 
		r2 = 3.14159;
		std::cout << "r2 = 3.14159: i: " << i << " r1: " << r1 << " d: " << d << " r2: " << r2 << "\n" << std::endl;
		r2 = r1;
		std::cout << "r2 = r1: i: " << i << " r1: " << r1 << " d: " << d << " r2: " << r2 << "\n" << std::endl;
		i = r2;
		std::cout << "i = r2: i: " << i << " r1: " << r1 << " d: " << d << " r2: " << r2 << "\n" << std::endl;
		r1 = d;
		std::cout << "r1 = d: i: " << i << " r1: " << r1 << " d: " << d << " r2: " << r2 << "\n" << std::endl;
		return(0);
}
