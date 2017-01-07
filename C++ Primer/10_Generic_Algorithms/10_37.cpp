#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

int main()
{
		std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		std::list<int> lst;
		std::size_t index = 0;
		std::vector<int>::reverse_iterator r3, r7;
		for (auto riter = ivec.rbegin(); riter != ivec.rend() and index <= 7; ++riter, ++index)
		{
				if (index == 3)
						r3 = riter;
				else if (index == 7)
						r7 = riter;
		}
		lst.resize(++r7 - r3);
		std::copy(r3, r7, lst.begin());
		for (const auto i : lst)
				std::cout << i << " ";
		std::cout << std::endl;
		return 0;
}
