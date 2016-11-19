#include <iostream>

int main()
{
		int i = 3;
		double d = 2.8;
		//i *= d;
		i *= static_cast<int>(d);
		std::cout << i << std::endl;
		return(0);
}
