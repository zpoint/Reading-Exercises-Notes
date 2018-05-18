#include <string>
#include <regex>
#include <iostream>
#include <algorithm>

int main()
{
		std::string data = "<person>\n"
						   " <first>Nico</first>\n"
						   " <last>Josuttis</last>\n"
						   "</person>\n";
		std::regex reg("<(.*)>(.*)</(\\1)>");

		// iterate over all matches (using a regex_token_iterator):
		std::sregex_token_iterator pos(data.cbegin(), data.cend(), reg, {0, 2}); // 0: full match, 2: second substring
		std::sregex_token_iterator end;
		for (; pos != end; ++pos)
				std::cout << "match:  " << pos->str() << std::endl;
		std::cout << std::endl;

		std::string names = "nico, jim, helmut, paul, tim, john paul, rita";
		std::regex sep("[ \t\n]*[,;.][ \t\n]*");  // separated by, ; or . and spaces
		std::sregex_token_iterator p(names.cbegin(), names.cend(), sep, -1);
		std::sregex_token_iterator e;
		for (; p != e; ++p)
				std::cout << "name:   " << *p << std::endl;

		return 0;
}
