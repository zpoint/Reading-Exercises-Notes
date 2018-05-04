#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

int main()
{
		// create empty vector for strings
		std::vector<std::string> sentence;

		// reserve memory for five elements to avoid reallocation
		sentence.reserve(5);

		// append some elements
		sentence.push_back("Hello,");
		sentence.insert(sentence.end(), {"how", "are", "you", "?"});

		// print elements separated with spaces
		std::copy(sentence.cbegin(), sentence.cend(), std::ostream_iterator<std::string>(std::cout, " "));
		std::cout << std::endl;

		// print "technical data"
		std::cout << " max_size(): " << sentence.max_size() << std::endl;
		std::cout << " size():     " << sentence.size() << std::endl;
		std::cout << " capacity(): " << sentence.capacity() << std::endl;

		// swap second and fourth element
		swap(sentence[1], sentence[3]);

		// insert element "always" before element "?"
		sentence.insert(std::find(sentence.begin(), sentence.end(), "?"), "always");

		// assign "!" to the last element
		sentence.back() = "!";

		// print elements separated with spaces
		std::copy(sentence.cbegin(), sentence.cend(), std::ostream_iterator<std::string>(std::cout, " "));
		std::cout << std::endl;

		// print some "technical data" again
		std::cout << " size():     " << sentence.size() << std::endl;
		std::cout << " capacity(): " << sentence.capacity() << std::endl;

		// delete last two elements
		sentence.pop_back();
		sentence.pop_back();
		// shrink capacity (since c++11)
		sentence.shrink_to_fit();

		// print some "technical data" again
		std::cout << " size():    " << sentence.size() << std::endl;
		std::cout << "capacity(): " << sentence.capacity() << std::endl;
		return 0;
}
