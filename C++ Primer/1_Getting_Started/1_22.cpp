#include <iostream>
#include "Sales_item.h"

int main()
{
		Sales_item item1, item2;
		std::cout << "Please enter transactions, different isbn to terminate" << std::endl;
		std::cin >> item1;
		item2 = item1;
		int i = 0;
		while (item1.isbn() == item2.isbn())
		{
				if (i != 0)
					item2 += item1;
				std::cout << item2 << std::endl;
				std::cin >> item1;
				i++;
		}
		return(0);
}
