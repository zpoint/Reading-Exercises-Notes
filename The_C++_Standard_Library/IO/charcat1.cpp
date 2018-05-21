#include <iostream>

int main()
{
		char c;

		// while it is possible to read a character
		while (std::cin.get(c))
				std::cout.put(c); // print it
		return 0;
}
