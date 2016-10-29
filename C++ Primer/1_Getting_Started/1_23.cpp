#include <iostream>
#include "Sales_item.h"

int main()
{
		Sales_item item1, prev;
		int count = 1;
		std::cout << "please enter transactions:" << std::endl;
		std::cin >> item1;
		while (std::cin >> prev)
		{
				if (item1.isbn() == prev.isbn())
				{
						count++;
						item1 += prev;
				}
				else
				{
						std::cout << "Total:" << count << "\t" << item1 << std::endl;
						count = 1;
						item1 = prev;
				}
		}
		return(0);
}
				
