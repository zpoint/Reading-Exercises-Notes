#include <list>
#include <vector>
#include <iostream>

int main()
{
		int ia[] = { 0, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
		std::vector<int> ivec;
		std::list<int> lst;
		for (auto i : ia)
		{
				ivec.emplace_back(i);
				lst.emplace_back(i);
		}
		
		std::vector<int>::iterator vec_iterator = ivec.begin();
		std::list<int>::iterator lst_iterator = lst.begin();
		while (vec_iterator != ivec.end())
		{
				if (!(*vec_iterator % 2))
						vec_iterator = ivec.erase(vec_iterator);
				else
						++vec_iterator;
		}
		
		while (lst_iterator != lst.end())
		{
				if (*lst_iterator % 2)
						lst_iterator = lst.erase(lst_iterator);
				else
						++lst_iterator;
		}

		std::cout << "After erase, ivec: " << std::endl;
		for (auto i : ivec)
				std::cout << i << " ";
		std::cout << std::endl;

		std::cout << "After erase, lst: " << std::endl;
		for (auto i : lst)
				std::cout << i << " ";
		std::cout << std::endl;

		return 0;
}
