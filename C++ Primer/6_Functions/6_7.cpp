#include <iostream>
int static_func()
{
	static unsigned x = 0;
	return(x++);
}

int main()
{
	for (auto x = 0; x < 10; ++x)
		std::cout << "The " << x + 1 << " th times call Result: " << static_func() << std::endl;
	return(0);
}