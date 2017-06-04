#include <iostream>

int main()
{
		bool t = true, f = false;
		int d = 10, oct = 010, hex = 0x10;
		std::cout << std::boolalpha << t << " " << f << std::endl << std::noboolalpha;
		std::cout << std::showbase << d << " " << oct << " " << hex << std::endl << std::noshowbase;
		/*
		 * etc ...
		 */
		return 0;
}
