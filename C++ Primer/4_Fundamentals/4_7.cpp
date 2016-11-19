#include <iostream>

int main()
{
		int i = 1 << 31;
		unsigned j = ~0;
		short k = 1 << 15;
		std::cout << "int i is : " << i << std::endl;
		std::cout << "After i - 1 is " << i - 1 << std::endl; // underflow
		i = ~i;
		std::cout << "int i is : " << i << std::endl;
		std::cout << "After i + 1 is " << i + 1 << std::endl; // overrflow

		std::cout << "unsigned j is: " << j << std::endl;
		std::cout << "After j + 1 is " << j + 1 << std::endl;

		std::cout << "short k is: " << k << std::endl;
		std::cout << "After k - 1 is: " << (short)(k - 1) << std::endl; // underflow
		k = ~k;
		std::cout << "short k is: " << k << std::endl;
		std::cout << "After k + 1 is: " << (short)(k + 1) << std::endl; // overflow
		return(0);
}

