#include <iostream>
#include <complex>
#include <cstdlib>
#include <limits>

int main()
{
		std::complex<long double> c1, c2;

		while (std::cin.peek() != EOF)
		{
				// read first complex number
				std::cout << "complex number 1: ";
				std::cin >> c1;
				if (!std::cin)
				{
						std::cerr << "input error" << std::endl;
						return EXIT_FAILURE;
				}

				// read second complex number
				std::cout << "complex number c2: ";
				std::cin >> c2;
				if (!std::cin)
				{
						std::cerr << "input error" << std::endl;
						return EXIT_FAILURE;
				}

				if (c1 == c2)
						std::cout << "c1 and c2 are equal !" << std::endl;

				std::cout << "c1 raised to the c2: " << std::pow(c1, c2) << std::endl << std::endl;

				// skip rest of the line
				std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		}

		return 0;
}
