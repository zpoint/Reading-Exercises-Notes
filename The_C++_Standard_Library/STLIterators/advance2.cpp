#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>

int main()
{
		std::istream_iterator<std::string> cinPos(std::cin);
		std::ostream_iterator<std::string> coutPos(std::cout, " ");

		// while input is not at the end of the file
		// - write every third string
		while (cinPos != std::istream_iterator<std::string>())
		{
				// ignore the following two string
				std::advance(cinPos, 2);

				// read and write the third string
				if (cinPos != std::istream_iterator<std::string>())
						*coutPos++ = *cinPos++;
		}
		std::cout << std::endl;

		return 0;
}
