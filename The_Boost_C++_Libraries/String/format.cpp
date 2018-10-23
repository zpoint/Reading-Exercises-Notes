#include <boost/format.hpp>
#include <iostream>

int main()
{
	std::cout << boost::format{"%%1%%.%%2%%.%%3%% %1%.%2%.%3%"} % 12 % 5 % 2014 << '\n';
	std::cout << boost::format{"%%2%%/%%1%%/%%3%% %2%/%1%/%3%"} % 12 % 5 % 2014 << '\n';
	/* special characters */
	std::cout << boost::format{"%|1$+| %2% %1%"} % 1 % 2 << '\n';
	return 0;
}
