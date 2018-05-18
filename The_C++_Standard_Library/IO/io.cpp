#include <cstdlib>
#include <iostream>

int main()
{
		double x, y; //operands

		// print header string
		std::cout << "Multiplication of two floating point values" << std::endl;

		// read first operand
		std::cout << "first operand:  ";
		if (! (std::cin >> x))
		{
				// input error
				// => error message and exit program with error status
				std::cerr << "error while reading the first floating value" << std::endl;
				return EXIT_FAILURE;
		}

		// read second operand
		std::cout << "second operand: ";
		if (! (std::cin >> y))
		{
				// input error
				// => error message and exit program with error status
				std::cerr << "error while reading the second floating value" << std::endl;
				return EXIT_FAILURE;
		}

		// print operands and result
		std::cout << x << " times " << y << " equals " << x * y << std::endl;

		return 0;
}
