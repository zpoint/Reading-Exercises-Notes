#include <locale>
#include <iostream>
#include <exception>
#include <cstdlib>

int main()
{
		try
		{
				// use German locale:
#ifdef _MSC_VER
				std::locale locG("deu_deu.1252");
#else
				std::locale locG("de_DE");
#endif
				const std::money_put<char>& mpG = std::use_facet<std::money_put<char>>(locG);
				
				// ensure that money_put<> facet impacts the output and current is written:
				std::cout.imbue(locG);
				std::cout << std::showbase;

				// use double as monetary value (use local symbol)
				mpG.put(std::cout, false, std::cout, ' ', 12345.678);
				std::cout << std::endl;

				// use string as monetary value (use international symbol)
				mpG.put(std::cout, true, std::cout, ' ', "12345.678");
				std::cout << std::endl;
		}
		catch (const std::exception& e)
		{
				std::cerr << "EXCEPTION: " << e.what() << std::endl;
				return EXIT_FAILURE;
		}

		return 0;
}
