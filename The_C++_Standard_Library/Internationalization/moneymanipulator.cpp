#include <locale>
#include <iostream>
#include <iomanip>
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

				// use German locale and ensure that the currency is written:
				std::cin.imbue(locG);
				std::cout.imbue(locG);
				std::cout << std::showbase;

				// read monetary value into long double (use international symbol)
				long double val;
				std::cout << "monetary value: ";
				std::cin >> std::get_money(val, true);

				if (std::cin)
				{
						// write monetary value (use local symbol)
						std::cout << std::put_money(val, false) << std::endl;
				}
				else
						std::cerr << "invalid format" << std::endl;
		}
		catch (const std::exception& e)
		{
				std::cerr << "Exception: " << e.what() << std::endl;
				return EXIT_FAILURE;
		}
		return 0;
}
