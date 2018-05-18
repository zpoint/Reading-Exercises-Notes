#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <locale>

int main()
{
		std::string input;

		// don't skip leading whitespaces
		std::cin.unsetf(std::ios::skipws);

		// read all characters while compressing whitespaces
		const std::locale& loc(std::cin.getloc()); // locale
		std::unique_copy(std::istream_iterator<char>(std::cin), // beginning of source
						 std::istream_iterator<char>(), // end of source
						 std::back_inserter(input),
						 [=] (char c1, char c2) { return std::isspace(c1, loc) && isspace(c2, loc); }
						);

		// process input
		// - here: write it to the standard output
		std::cout << input;
		return 0;
}
