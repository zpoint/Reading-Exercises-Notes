#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

int main()
{
		std::copy(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>(), std::ostream_iterator<std::string>(std::cout, "\n"));
		return 0;
}
