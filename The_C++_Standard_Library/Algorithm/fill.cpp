#include "algostuff.hpp"

int main()
{
		// print ten times 7.7
		std::fill_n(std::ostream_iterator<float>(std::cout, " "), // beginning of destination
						10, // count
						7.7); // new value
		std::cout << std::endl;

		std::list<std::string> coll;

		// insert "hello" nine times
		std::fill_n(std::back_inserter(coll), // beginning of destination
						9, // count
						"hello"); // new value
		PRINT_ELEMENTS(coll, "coll:  ");

		// overwrite all elements with "again"
		std::fill(coll.begin(), coll.end(), "again");
		PRINT_ELEMENTS(coll, "coll:  ");

		// replace all but two elements with "hi"
		std::fill_n(coll.begin(), coll.size() - 2, "hi");
		PRINT_ELEMENTS(coll, "coll:   ");

		// replace the second and up to the last element but one with "hmmm"
		std::list<std::string>::iterator pos1, pos2;
		pos1 = coll.begin();
		pos2 = coll.end();
		std::fill(++pos1, --pos2, "hmmm");
		PRINT_ELEMENTS(coll, "coll:   ");

		return 0;
}
