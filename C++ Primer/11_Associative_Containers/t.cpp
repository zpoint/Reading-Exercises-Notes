#include <set>
#include <iostream>

int main()
{
		std::set<int> iset{1, 2, 3, 4, 5};
		std::set<int>::iterator b = iset.begin(), e = iset.begin();
		++e;
		auto i = iset.erase(b, e);
		std::cout << *i << std::endl;
		for (const auto &item : iset)
				std::cout << item << " ";
		std::cout << std::endl;
		return 0;
}
