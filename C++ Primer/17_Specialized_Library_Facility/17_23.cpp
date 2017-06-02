#include <iostream>
#include <string>
#include <regex>

int main()
{
		std::string zip_codes = "\\d{5}-?\\d{4}";
		std::regex r(zip_codes);
		std::smatch m;
		std::string line;
		bool matched = false;
		while (std::getline(std::cin, line))
		{
				matched = false;
				for (std::sregex_iterator it(line.begin(), line.end(), r), end_it; it != end_it; ++it)
				{
						matched = true;
						std::cout << "Matched: " << it->str() << std::endl;
				}
				if (not matched)
						std::cout << "No match for: " << line << std::endl;
		}
		return 0;
}
