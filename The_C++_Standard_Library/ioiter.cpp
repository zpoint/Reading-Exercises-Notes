#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

int main()
{
		std::vector<std::string> coll;

		// read all words from the standard input
		// - source: all strings until end-of-file (or error)
		// - destination: coll(inserting)
		std::copy(std::istream_iterator<std::string>(std::cin),
				  std::istream_iterator<std::string>(),
				  std::back_inserter(coll));

		// sort elements
		std::sort(coll.begin(), coll.end());

		// print all elements without duplicates
		// - source: coll
		// -destination: standard output (with newline between elements)
		std::unique_copy(coll.cbegin(), coll.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));
		return 0;
		return 0;
}
