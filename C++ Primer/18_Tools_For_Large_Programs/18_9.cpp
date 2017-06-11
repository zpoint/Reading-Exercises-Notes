#include <iostream>
#include "Sales_date.h"

int main()
{
		Sales_data item1, item2, sum;
		while (std::cin >> item1 >> item2)
		{
				try
				{
						sum = item1 + item2;
				}
				catch (const isbn_mismatch &e)
				{
						std::cout << "catched" << std::endl;
						std::cerr << e.what() << ": left isbn(" << e.left << ") right isbn(" << e.right << ")" << std::endl;
				}
		}
		return 0;
}
