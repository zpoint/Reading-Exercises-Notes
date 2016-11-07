#include <iostream>

int main()
{
		std::cout << "Expected -86: " << -30 * 3 + 21 / 5 << std::endl;
		std::cout << "Expected -18: " << -30 + 3 * 21 / 5 << std::endl;
		std::cout << "Expected 0: " << 30 / 3 * 21 % 5 << std::endl;
		std::cout << "Expected -2: " << -30 / 3 * 21 % 4 << std::endl;
		return(0);
}	
