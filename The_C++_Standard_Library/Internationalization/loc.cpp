#include <iostream>
#include <locale>
#include <exception>
#include <cstdlib>

int main()
{
		try
		{
				// use classic C locale to read data from standard input
				std::cin.imbue(std::locale::classic());

				// use a German locale to write data to standard output
				// - use different locale names for Windows and POSIX
#ifdef _MSC_VER
				std::cout.imbue(std::locale("deu_deu.1252"));
#else
				std::cout.imbue(std::locale("de_DE"));
#endif

				// read and output floating-point values in a loop
				std::cout << "input floating-point values (classic notation): " << std::endl;
				double value;
				while (std::cin >> value)
						std::cout << value << std::endl;
		}
		catch (const std::exception& e)
		{
				std::cerr << "Exception: " << e.what() << std::endl;
				return EXIT_FAILURE;
		}

		return 0;
}
