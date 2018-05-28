#include <locale>
#include <ctime>
#include <iterator>
#include <iostream>
#include <string>
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
				// std::locale locG("de_DE.ISO-8859-1");
				std::locale locG("de_DE");
#endif
				const std::time_get<char>& tgG = std::use_facet<std::time_get<char>>(locG);

				// print date order for German locale:
				typedef std::time_base TB;
				std::time_get<char>::dateorder d = tgG.date_order();
				std::cout << "dateorder: "
						  << (d == TB::no_order || d == TB::mdy ? "mdy" : 
										           d == TB::dmy ? "dmy" : 
												   d == TB::ymd ? "ymd" :
												   d == TB::ydm ? "ydm" : "unknown") << std::endl;

				// read weekday (in German) and time (hh:mm))
				std::cout << "<wochentag> <hh>:<mm>: ";
				std::string format = "%A %H:%M";
				struct tm val;
				std::ios_base::iostate err = std::ios_base::goodbit;
				tgG.get(std::istreambuf_iterator<char>(std::cin),
						std::istreambuf_iterator<char>(),
						std::cin, err, &val,
						format.c_str(), format.c_str() + format.size());
				if (err != std::ios::goodbit)
						std::cerr << "invalid format" << std::endl;
		}
		catch (const std::exception& e)
		{
				std::cerr << "Exception: " << e.what() << std::endl;
				return EXIT_FAILURE;
		}

		return 0;
}
