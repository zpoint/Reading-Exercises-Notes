#include <iostream>
#include <regex>

int main()
{
		std::string rgx_str;
		while (std::cin >> rgx_str)
		{
				try
				{
				std::regex r(rgx_str, std::regex::icase);
				std::smatch results;
				std::string filename = "111.cpp";
				if (std::regex_search(filename, results, r))
						std::cout << results.str() << std::endl;
				}
				catch (std::regex_error e)
				{
						std::cout << e.what() << "\n code: " << e.code() << std::endl;
				}
		}
		return 0;
}
