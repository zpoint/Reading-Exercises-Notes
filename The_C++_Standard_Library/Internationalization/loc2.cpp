#include <iostream>
#include <locale>
#include <string>
#include <cstdlib>
#include <exception>

int main()
{
		try
		{
				// create the default locale from the user's environment
				std::locale langLocale("");

				// and assign it tot he standard output channel
				std::cout.imbue(langLocale);

				// process the name of the locale to find out whether German is used
				std::cout << langLocale.name() << std::endl;
				bool isGerman = (langLocale.name().substr(0, 2) == "de" ||
								 langLocale.name().substr(0, 3) == "ger" ||
								 langLocale.name().substr(0, 3) == "Ger");

				// read locale for the input
				std::cout << (isGerman ? "Sprachumgbung fuer Eingaben: " : "Locale for input:  ") << std::endl;
				std::string s;
				std::cin >> s;
				if (!std::cin)
				{
						if (isGerman)
						{
								std::cerr << "FEHLER beim Einlesen der Sprachumgebung" << std::endl;
						}
						else
						{
								std::cerr << "ERROR while reading the locale" << std::endl;
						}
						return EXIT_FAILURE;
				}
				std::locale cinLocale(s); // create locale by string(since C++ 11)

				// and assign it to the standard input channel
				std::cin.imbue(cinLocale);

				// read and output floating-point values in a loop
				std::cout << (isGerman ? "Gleitkommawerte: " : "Floating-point values: ") << std::endl;

				double value;
				while (std::cin >> value)
						std::cout << value << std::endl;
		}
		catch (const std::exception& e)
		{
				std::cerr << "Exception: " << e.what() << std::endl;
				return EXIT_FAILURE;
		}
}
