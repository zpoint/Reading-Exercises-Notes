#include <iostream>
#include <stdexcept>

class exceptionType
{
};

typedef int EXCEPTYPE;

void a()
{
		try
		{
				exceptionType *ptr = new exceptionType();
				std::cout << "Created ptr: " << ptr << std::endl;
				throw ptr;
		}
		catch (exceptionType *pet)
		{
				std::cout << "Catch pet: " << pet << std::endl;
				delete pet;
		}
}

void b()
{
		try
		{
				throw std::runtime_error("Run error");
		}
		catch (...)
		{
				std::cout << "Catch any" << std::endl;
		}
}

void c()
{
		try
		{
				throw 1;
		}
		catch (EXCEPTYPE e)
		{
				std::cout << e << std::endl;
		}
}


int main()
{
		a();
		b();
		c();
		return 0;
}
