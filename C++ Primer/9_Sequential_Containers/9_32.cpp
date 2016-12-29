#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

int main()
{
		// legal, iter++ return prev_iter, and increment iter, insert(iter, *prev_iter) won't affect result
		// list
		std::list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		auto iter = li.begin(); 
		while (iter != li.end())
		{
				if (*iter % 2)
				{
						iter = li.insert(iter, *iter++);
						++iter;
				}
				else
						iter = li.erase(iter);
		}
		for (const auto i : li)
				std::cout << i << " " << std::endl;
		std::cout << std::endl;
		return 0;
}
