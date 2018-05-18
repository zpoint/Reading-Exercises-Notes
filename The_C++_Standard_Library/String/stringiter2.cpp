#include <string>
#include <iostream>
#include <algorithm>

int main()
{
		// create constant string
		const std::string hello("Hello, how are you?");

		// initialize string s with all characters of string hello
		std::string s(hello.cbegin(), hello.cend());

		// ranged-based for loop thar iterates through all the characters
		for (char c : s)
				std::cout << c;
		std::cout << std::endl;

		// reverse the order of all characters inside the string
		std::reverse(s.begin(), s.end());
		std::cout << "reverse:        " << s << std::endl;

		// sort all characters inside the string
		std::sort(s.begin(), s.end());
		std::cout << "ordered:        " << s << std::endl;

		// remove adjacent duplicates
		// - unique() reorders and returns new end
		// - erase() shrinks accordingly
		s.erase(std::unique(s.begin(), s.end()), s.end());
		std::cout << "no duplicates:   " << s << std::endl;

		return 0;
}
