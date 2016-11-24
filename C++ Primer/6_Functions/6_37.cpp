#include <string>
#include <iostream>

std::string (&func(std::string(&x)[10])) [10]
{
		return x;
}

// number 1
typedef std::string (&TypeArr)[10];

TypeArr func1(TypeArr x)
{
		return x;
}

// number 2
auto func2(std::string(&x)[10]) -> std::string(&)[10]
{
		return x;
}

// number 3
std::string T[10] = {"12", "34"};
decltype(T) &func3(decltype(T) &x)
{
		return x;
}

int main()
{
		std::string (&x)[10] = T;
		std::cout << T << std::endl;
		std::cout << "0 " << func(x) << std::endl;
		std::cout << "1 " << func1(x) << std::endl;
		std::cout << "2 " << func2(x) << std::endl;
		std::cout << "3 " << func3(x) << std::endl;
		return 0;
}
