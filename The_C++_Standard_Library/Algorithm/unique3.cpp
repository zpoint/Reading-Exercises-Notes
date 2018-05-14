#include <iostream>
#include <algorithm>
#include <iterator>

bool bothSpaces (char elem1, char elem2)
{
		return elem1 == ' ' && elem2 == ' ';
}

int main()
{
		// don't skip leading whitespaces by default
		std::cin.unsetf(std::ios::skipws);

		// copy standart input to standard output
		// - while compressing spaces
		std::unique_copy(std::istream_iterator<char>(std::cin), // beginning of source: cin
						 std::istream_iterator<char>(), // end of source: end-of-file
						 std::ostream_iterator<char>(std::cout), // destination: cout
						 bothSpaces); // duplicate criterion

		return 0;
}
