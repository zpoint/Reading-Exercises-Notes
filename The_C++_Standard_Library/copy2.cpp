#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <deque>
#include <set>
#include <iostream>

template <typename T>
void pr_container(const T& container, std::string val="")
{
		std::cout << val << " size: " << container.size() << "\n";
		for (const auto& i : container)
				std::cout << i << " ";
		std::cout << "\n" << std::endl;
}

int main()
{
		std::list<int> coll1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		// copy the elements of coll1 into coll2 by appending them
		std::vector<int> coll2;
		std::copy(coll1.cbegin(), coll1.cend(), std::back_inserter(coll2));
		pr_container(coll2, "coll2");

		// copy the elements of coll1 into coll3 by inserting them on the front
		// - reverses the order of the elements
		std::deque<int> coll3;
		std::copy(coll1.cbegin(), coll1.cend(), std::front_inserter(coll3));
		pr_container(coll3, "coll3");

		// copy elements of coll1 into coll4
		// - only inserter that works for associative collections
		std::set<int> coll4;
		std::copy(coll1.cbegin(), coll1.cend(), std::inserter(coll4, coll4.begin()));
		pr_container(coll4, "coll4");
		return 0;
}
