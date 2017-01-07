#include <iostream>
#include <list>
#include <algorithm>

int main()
{
		std::list<int> lst{0, 1, 2, 3, 4, 5, 6, 7 ,9, 0, 6};
		auto iter = std::find(lst.rbegin(), lst.rend(), 0);
		for (; iter != lst.rbegin(); ++iter)
				std::cout << *iter << " ";
		std::cout << std::endl;
		return 0;
}
