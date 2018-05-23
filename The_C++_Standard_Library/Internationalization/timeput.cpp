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
				// query local time:
				std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
				std::time_t t = std::chrono::system_clock::to_time_t(now);
				tm* nowTM = std::localtime(&t);

				// print local time with the global classic locale:
				std::locale locC;
				const std::time_put<char>& tpC = std::use_facet<std::time_put<char>>(locC);

				// use single conversion specifier
				tpC.put(std::cout, std::cout, ' ', nowTM, 'x');
				std::cout << std::endl;

				// use format string:
				std::string format = "%A %x %I%p\n %W %w\n"; // format: week date hour
				tpC.put(std::cout, std::cout, ' ', nowTM, format.c_str(), format.c_str() + format.size());

				// print local time with German locale:
#ifdef _MSC_VER
				std::locale locG("deu_deu.1252");
#else
				std::locale locG("de_DE");
#endif
				const std::time_put<char>& tpG = std::use_facet<std::time_put<char>>(locG);
				tpG.put(std::cout, std::cout, ' ', nowTM, 'x');
				std::cout << std::endl;
				tpG.put(std::cout, std::cout, ' ', nowTM, format.c_str(), format.c_str() + format.size());
		}
		catch (const std::exception& e)
		{
				std::cerr << "Exception: " << e.what() << std::endl;
				return EXIT_FAILURE;
		}

		return 0;
}
