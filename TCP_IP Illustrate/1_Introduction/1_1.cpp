#include <iostream>
#include <iomanip>

int main()
{
		// max a
		unsigned mask_a = 1 << 31;
		std::cout << "Max of A is : " << std::dec << ~mask_a << std::endl;
		std::cout << "Max of A is : " << std::hex << ~mask_a << std::endl;
		// max b
		unsigned mask_b = 1 << 30;
		mask_b = ~mask_b;
		std::cout << "Max of B is : " << std::dec << mask_b << std::endl;
		std::cout << "Max of B is : " << std::hex << mask_b << std::endl;
		// max c
		unsigned mask_c = 1 << 29;
		mask_c = ~mask_c;
		std::cout << "Max of C is : " << std::dec << mask_c << std::endl;
		std::cout << "Max of C is : " << std::hex << mask_c << std::endl;
		return 0;
}
