#include <bitset>
#include <iostream>
#include <string>
#include <limits>

int main()
{
		// print some numbers in binary representation
		std::cout << "267 as binary short:     " 
				  << std::bitset<std::numeric_limits<unsigned short>::digits>(267)
				  << std::endl;

		std::cout << "267 as binary long:      "
				  << std::bitset<std::numeric_limits<unsigned long>::digits>(267)
				  << std::endl;

		std::cout << "10,000,000 with 24 bits: "
				  << std::bitset<24>(1e7) << std::endl;

		// write binary representation into string
		std::string s = std::bitset<42>(12345678).to_string();
		std::cout << "12,345,678 with 42 bits: " << s << std::endl;

	   // transform binary representation into integral number
		std::cout << "\"1000101011\" as number:"
				  << std::bitset<100>("1000101011").to_ullong() << std::endl;

		return 0;
}
