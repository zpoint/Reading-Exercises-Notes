#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>

int main()
{
		// create empty deque of strings
		std::deque<std::string> coll;

		// insert several elements
		coll.assign(3, std::string("string"));
		coll.push_back("last string");
		coll.push_front("first string");

		// print elements separated by newlines
		std::copy(coll.cbegin(), coll.cend(),
				  std::ostream_iterator<std::string>(std::cout, "\n"));
		std::cout << std::endl;

		// remove first and last element
		coll.pop_front();
		coll.pop_back();
		
		// insert "another" into every element but the first
		for (std::size_t i = 1; i < coll.size(); ++i)
				coll[i] = "another " + coll[i];

		// change size to four elements
		coll.resize(4, "resized string");

		// print elements seperated by newlines
		std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));

		std::cout << "size:     " << coll.size() << "\n" <<
				     "max_size: " << coll.max_size() << "\n";
		return 0;
}
