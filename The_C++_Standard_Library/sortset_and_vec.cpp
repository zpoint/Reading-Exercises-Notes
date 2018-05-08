#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <set>
#include <vector>

void vector_version()
{
		// create a string vector
		// - initialized by all words from standard input
		std::vector<std::string> coll((std::istream_iterator<std::string>(std::cin)), std::istream_iterator<std::string>());

		// sort elements
		std::sort(coll.begin(), coll.end());

		// print all elements ignoring subsequent duplicates
		std::unique_copy(coll.cbegin(), coll.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));
}

int main()
{
		// create a string set
		// - initialized by all words from standard input
		std::set<std::string> coll((std::istream_iterator<std::string>(std::cin)), std::istream_iterator<std::string>());

		// print all elements
		std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));

		return 0;
}
