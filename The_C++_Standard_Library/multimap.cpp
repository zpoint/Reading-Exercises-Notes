#include <map>
#include <string>
#include <iostream>

int main()
{
		std::multimap<int, std::string> coll; // container for int/string values

		// assign some elements in arbitrary order
		// - a value with key 1 gets inserted twice
		coll = { {5, "tagged"},
				 {2, "a"},
				 {1, "this"},
				 {4, "of"},
				 {6, "string"},
				 {1, "is"},
				 {3, "multimap"}
		};

		// print all element values
		// -element member sceond is the value
		for (auto elem : coll)
				std::cout << elem.second << ' ';

		std::cout << std::endl;
		return 0;
}
