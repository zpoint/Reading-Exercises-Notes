#include <iostream>
#include <algorithm>
#include <locale>
#include <string>

char myToupper(char c)
{
		std::locale loc;
		return std::use_facet<std::ctype<char>>(loc).toupper(c);
}

int main()
{
		std::string s("Internationalization");
		std::string sub("Nation");

		// search substring case insensitive
		std::string::iterator pos;
		pos = std::search(s.begin(), s.end(),
						sub.begin(), sub.end(),
						[] (char c1, char c2) { return myToupper(c1) == myToupper(c2); });

		if (pos != s.end())
				std::cout << "\"" << sub << "\" is part of \"" << s << "\"" << std::endl;

		return 0;
}
