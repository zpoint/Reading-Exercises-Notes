#include <boost/logic/tribool_io.hpp>
#include <iostream>

using namespace boost::logic;

int main()
{
		tribool b;
		std::cout << std::boolalpha << b << '\n';

		b = true;
		b = false;
		b = indeterminate;
		if (b);
		else if (!b);
		else
				std::cout << "indeterminate\n" << std::endl;
		return 0;
}
