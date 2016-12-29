#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

int main()
{
		// list
		std::list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		auto iter = li.begin(); 
		while (iter != li.end())
		{
				if (*iter % 2)
				{
						iter = li.insert(iter, *iter);
						++iter;
						++iter;
				}
				else
						iter = li.erase(iter);
		}
		for (const auto i : li)
				std::cout << i << " " << std::endl;
		std::cout << std::endl;
		// forward_list
		std::forward_list<int> fli = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		auto fiter = fli.begin(), prev = fli.before_begin(); 
		while (fiter != fli.end())
		{
#ifdef NDEBUG
				std::cout << "Before: " << std::endl;
				std::cout << "prev: " << *prev << std::endl;
				std::cout << "fiter: " << *fiter << std::endl;
				for (const auto i : fli)
						std::cout << i << " ";
#endif
				std::cout << std::endl;
				if (*fiter % 2)
				{
						fiter = fli.insert_after(fiter, *fiter);
						++fiter;
						++prev;
						++prev;
				}
				else
						fiter = fli.erase_after(prev);
#ifdef NDEBUG
				std::cout << "After: " << std::endl;
				std::cout << "prev: " << *prev << std::endl;
				std::cout << "fiter: " << *fiter << std::endl;
				for (const auto i : fli)
						std::cout << i << " ";
				std::cout << std::endl;
#endif
		}
		for (const auto i : fli)
				std::cout << i << " " << std::endl;
		std::cout << std::endl;
		return 0;
}
