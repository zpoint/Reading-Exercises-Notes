#include <iostream>
#include <exception>
#include <cstdlib>
#include "sum1a.cpp"

int main()
{
		double sum;

		try
		{
				sum = MyLib::readAndProcessSum(std::cin);
		}
		catch (const std::ios::failure& error)
		{
				std::cerr << "I/O exception: " << error.what() << std::endl;
				return EXIT_FAILURE;
		}
		catch (const std::exception& error)
		{
				std::cerr << "standard exception: " << error.what() << std::endl;
				return EXIT_FAILURE;
		}
		catch (...)
		{
				std::cerr << "unknown exception" << std::endl;
				return EXIT_FAILURE;
		}

		// print sum
		std::cout << "sum: " << sum << std::endl;
}
