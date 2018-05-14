#include "algostuff.hpp"


int main()
{
		std::vector<int> coll1 = { 1, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		PRINT_ELEMENTS(coll1, "coll1:    ");

		// check whether coll1 is sorted
		if (std::is_sorted(coll1.begin(), coll1.end()))
				std::cout << "coll1 is sorted" << std::endl;
		else
				std::cout << "coll1 is not sorted" << std::endl;

		std::map<int, std::string> coll2;
		coll2 = { {1, "Bill"}, {2, "Jim"}, {3, "Nico"}, {4, "Liu"}, {5, "Ai"} };
		PRINT_MAPPED_ELEMENTS(coll2, "coll2:   ");

		// define predicate to compare names
		auto compareName = [] (const std::pair<int, std::string>& e1, const std::pair<int, std::string>& e2) { return e1.second < e2.second; };

		// check whether the name in coll2 are sorted
		if (std::is_sorted(coll2.cbegin(), coll2.cend(), compareName))
				std::cout << "names in coll2 are sorted" << std::endl;
		else
				std::cout << "names in coll2 are not sorted" << std::endl;

		// print first unsorted name
		std::map<int, std::string>::const_iterator pos = std::is_sorted_until(coll2.cbegin(), coll2.cend(), compareName);
		if (pos != coll2.cend())
				std::cout << "first unsorted name: " << pos->second << std::endl;

		return 0;
}
