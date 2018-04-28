#include <set>
#include <string>
#include <iostream>

int main()
{
		std::multiset<std::string> cities {
				"Braunschweig", "Hanover", "Frankfurt", "New York",
				"Chicago", "Tornoto", "Pairs", "Frankfurt"
		};

		// print each element:
		for (const auto& elem : cities)
				std::cout << elem << "  ";
		std::cout << std::endl;

		// insert additional values:
		cities.insert({"London", "Munich", "Hanover", "Braunschweig"});

		// print each element:
		for (const auto & elem : cities)
				std::cout << elem << "  ";
		std::cout << std::endl;
		return 0;
}
