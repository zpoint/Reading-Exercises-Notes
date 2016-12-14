#include <list>
#include <iostream>

int main()
{
		std::list<int> lst1;
		std::list<int>::iterator iter1 = lst1.begin(),
								 iter2 = lst1.end();

		while (std::distance(iter1, iter2) > 0)
				std::cout << "while loop" << std::endl;
		return 0;
}
