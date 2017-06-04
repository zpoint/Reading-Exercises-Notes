#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
		double f1 = 100 * std::sqrt(2.0);
		int i = 12345;
		std::cout << "hexadecimal: " << std::uppercase << std::hexfloat << std::setw(20) << f1 << "\n" << "hexadecimal: " << std::setw(20) << i << "\n" << std::endl;
		return 0;
}
