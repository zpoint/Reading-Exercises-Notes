#include <iostream>
#include "Sales_date.h"

int main()
{
		Sales_data item1, item2, sum;
		while (std::cin >> item1 >> item2)
		{
				if (item1.bookNo == "q")
						break;
				try
				{
						sum = item1 + item2;
				}
				catch (const isbn_mismatch &e)
				{
						std::cerr << e.what() << ": left isbn(" << e.left << ") right isbn(" << e.right << ")" << std::endl;
				}
		}
		std::cout << "No no try block" << std::endl;
		while (std::cin >> item1 >> item2)
		{
				sum = item1 + item2;
		}
		return 0;
}
