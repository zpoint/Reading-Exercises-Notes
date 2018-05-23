#include <locale>
#include <chrono>
#include <ctime>
#include <iostream>
#include <exception>
#include <cstdlib>

int main()
{
		try
		{
				// print floating-point value with the global classic locale:
				std::locale locC;
				std::cout.imbue(locC);
				std::use_facet<std::num_put<char>>(locC).put(std::cout, std::cout, ' ', 1234.5678);
				std::cout << std::endl;

				// print floating-point value with German locale:
#ifdef _MSC_VER
				std::locale locG("deu_deu.1252");
#else
				std::locale locG("de_DE");
#endif
				std::cout.imbue(locG);
				std::use_facet<std::num_put<char>>(locG).put(std::cout, std::cout, ' ', 1234.5678);
				std::cout << std::endl;
		}
		catch (const std::exception& e)
		{
				std::cerr << "Exception: " << e.what() << std::endl;
				return EXIT_FAILURE;
		}
}

