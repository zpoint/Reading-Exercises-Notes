#include <string>
#include <regex>
#include <iostream>
#include <iterator>

int main()
{
		std::string data = "<person>\n"
						   "<first>Nico</first>\n"
						   "<last>Josuttis</last>\n"
						   "</person>\n";

		std::regex reg("<(.*)>(.*)</(\\1)>");

		// print data with replacement for matched patterns
		std::cout << std::regex_replace(data, // data
										reg,  // regular expression 
										"<$1 value=\"$2\"/>") // replacement
				  << std::endl;
		
		// same using sed syntax
		std::cout << std::regex_replace(data,
									 	reg,
										"<\\1 value=\"\\2\"/>",
										std::regex_constants::format_sed)
				  << std::endl;

		// use iterator interface, and
		// - format_no_copy: don't copy characters that don't match
		// - format_first_only: replace only the first match found
		std::string res2;
		std::regex_replace(std::back_inserter(res2), // destination
						   data.begin(), data.end(), // source range
						   reg,
						   "<$1 value=\"$2\"/>",
						   std::regex_constants::format_no_copy | std::regex_constants::format_first_only 
						   );
		std::cout << res2 << std::endl;

		return 0;
}
