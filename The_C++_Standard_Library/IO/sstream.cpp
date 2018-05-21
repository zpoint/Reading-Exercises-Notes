#include <iostream>
#include <sstream>
#include <bitset>

int main()
{
		std::ostringstream os;

		// decimal and hexadecimal value
		os << "dec: " << 15 << std::hex << " hex: " << 15 << std::endl;
		std::cout << os.str() << std::endl;

		// append floating value and bitset
		std::bitset<15> b(5789);
		os << "float: " << 4.67 << " bitset: " << b << std::endl;


		std::cout << "before seek: " << os.str() << std::endl;
		// overwtite with octal value
		os.seekp(0);
		os << "oct: " << std::oct << 15;
		std::cout << os.str() << std::endl;

		return 0;
}
