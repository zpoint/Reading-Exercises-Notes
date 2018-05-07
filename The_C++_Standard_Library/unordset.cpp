#include <iostream>
#include <unordered_set>
#include <numeric>

template <typename T>
void PRINT_ELEMENTS(const T& container, const std::string& val="")
{
		std::cout << val << ": ";
		for (const auto &item: container)
				std::cout << item << " ";
		std::cout << std::endl;
}

int main()
{
		// create and initialize unordered set
		std::unordered_set<int> coll = { 1, 2, 3, 5, 7, 11, 13, 17, 19, 77 };

		// print elements
		// - elements are in arbitrary order
		PRINT_ELEMENTS(coll);

		// insert some additional elements
		// - might cause rehashing and create different order
		coll.insert({ -7, 17, 33, -11, 17, 19, 1, 13 });
		PRINT_ELEMENTS(coll);

		// remove element with specific value
		coll.erase(33);

		// insert sum of all existing values
		coll.insert({std::accumulate(coll.cbegin(), coll.cend(), 0)});
		PRINT_ELEMENTS(coll);

		// check if value 19 is in the set
		if (coll.find(19) != coll.end())
				std::cout << "19 is available" << std::endl;

		// remove all negative values
		std::unordered_set<int>::iterator pos;
		for (pos = coll.begin(); pos != coll.end(); )
		{
				if (*pos < 0)
						pos = coll.erase(pos);
				else
						++pos;
		}
		PRINT_ELEMENTS(coll);

		return 0;
}
