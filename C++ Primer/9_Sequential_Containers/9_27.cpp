#include <forward_list>
#include <iostream>

int main()
{
		std::forward_list<int> flst{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		std::forward_list<int>::iterator flst_iterator = flst.begin(), prev_iterator = flst.before_begin();
		std::cout << "Before remove:" << std::endl;
		for (const auto i : flst)
				std::cout << i << " ";
		std::cout << std::endl;
		while (flst_iterator != flst.end())
		{
				if (*flst_iterator % 2)
						flst_iterator = flst.erase_after(prev_iterator);
				else
				{
						++prev_iterator;
						++flst_iterator;
				}
		}
		std::cout << "After process: " << std::endl;
		for (const auto i : flst)
				std::cout << i << " ";
		std::cout << std::endl;
		return 0;
}
