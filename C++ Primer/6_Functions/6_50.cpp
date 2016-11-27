#include <iostream>

void f()
{
		std::cout << "Calling f()" << std::endl;
}

void f(int i)
{
		std::cout << "Calling f(int) " << i << std::endl;
}

void f(int i, int j)
{
		std::cout << "Calling f(int , int) " << i << " " << j << std::endl;
}

void f(double i, double j=3.14)
{
		std::cout << "Calling f(double, double) " << i << " " << j << std::endl;
}

int main()
{
		std::cout << "f(2.56, 42.0)" << std::endl;
		f(2.56, 42.0);
		std::cout << "f(42)" << std::endl;
		f(42);
		std::cout << "f(42, 0)" << std::endl;
		f(42, 0);
		std::cout << "f(2.56, 3.14)" << std::endl;
		f(2.56, 3.14);
		return 0;

}
