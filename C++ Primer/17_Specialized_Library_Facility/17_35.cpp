#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
		std::cout << "hexadecimal: " << std::uppercase << std::hexfloat << 100 * std::sqrt(2.0) << std::endl;
		return 0;
}
