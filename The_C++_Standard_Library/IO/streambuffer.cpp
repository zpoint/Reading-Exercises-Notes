#include <iostream>
#include <fstream>

int main()
{
		// stream for hexadecimal standard output
		std::ostream hexout(std::cout.rdbuf());
		hexout.setf(std::ios::hex, std::ios::basefield);
		hexout.setf(std::ios::showbase);

		// switch bwtween decimal and hexadecimal output
		hexout <<    "hexout: " << 177 << " ";
		std::cout << "cout:   " << 177 << " ";
		hexout <<    "hexout: " << -49 << " ";
		std::cout << "cout:   " << -49 << " ";
		hexout << std::endl;

		return 0;
}
