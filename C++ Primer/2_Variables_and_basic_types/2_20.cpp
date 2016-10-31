#include <iostream>

int main()
{
		int i = 42;
		int *pi = &i;
		*pi = *pi * *pi;
		std::cout << "*pi: " << *pi << std::endl;
		return(0);
}
