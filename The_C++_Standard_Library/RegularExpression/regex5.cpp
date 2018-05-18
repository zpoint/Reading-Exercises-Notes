#include <regex>
#include <iostream>
#include "regexexception.hpp"
int main()
{
		try
		{
				// initialize regular expression with invalid syntax
				std::regex pat("\\\\.*index\\{([^}]*)\\}", std::regex_constants::grep | std::regex_constants::icase);
		}
		catch (const std::regex_error& e)
		{
				std::cerr << "regex_error: \n"
						  << "what(): " << e.what() << "\n"
						  << "code(): " << regexCode(e.code()) << std::endl;
		}
		return 0;
}

