#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <regex>

int main()
{
		// create a string
		std::string s("The zip code of Braunschweig in Germany is 38100");
		std::cout << "original: " << s << std::endl;

		// lowercase all characters
		std::transform(s.cbegin(), s.cend(), s.begin(), [] (char c) { return std::tolower(c); });
		std::cout << "lowered:  " << s << std::endl;

		// uppercase all characters
		std::transform(s.cbegin(), s.cend(), s.begin(), [] (char c) { return std::toupper(c); });
		std::cout << "uppered:  " << s << std::endl;

		// search case-insensitive for Germany
		std::string g("Germany");
		std::string::const_iterator pos;
		pos = std::search(s.cbegin(), s.cend(), // source string in which to search
						  g.cbegin(), g.cend(), // substring to search
						  [] (char c1, char c2) { return std::toupper(c1) == std::toupper(c2); }
						  );
		if (pos != s.cend())
		{
				std::cout << "substring \"" << g << "\" found at index " << pos - s.cbegin() << std::endl;
		}

		return 0;
}
