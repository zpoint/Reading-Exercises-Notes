#include <iostream>
#include <cctype>

uint32_t swar(uint32_t i)
{
		std::cout << std::showbase << std::hex;
		i = (i & 0x55555555) + ((i >> 1) & 0x55555555);
		std::cout << "first:  " << i << std::endl;
		i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
		std::cout << "second: " << i << std::endl; 
		i = (i & 0x0F0F0F0F) + ((i >> 4) & 0x0F0F0F0F);
		std::cout << "third: " << i << std::endl;
		i = (i * (0x01010101) >> 24);
		std::cout << "final: " << i << std::endl;
		return i;
}

int main()
{
		std::cout << "result: \n" << swar(0x3A70F21B) << std::endl;
}
