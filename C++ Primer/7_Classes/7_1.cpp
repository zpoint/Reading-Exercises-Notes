#include <iostream>
#include <string>

struct Sales_data {
		std::string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;
};

int main()
{
		Sales_data total;
		if (std::cin >> total.bookNo >> total.units_sold)
		{
				Sales_data trans;
				while (std::cin >> trans.bookNo >> trans.units_sold)
				{
						if (total.bookNo == trans.bookNo)
						{
								total.units_sold += trans.units_sold;
						}
						else
						{
								std::cout << total.bookNo << " " << total.units_sold << std::endl;
								total = trans;
						}
				}
				std::cout << total.bookNo << " " << total.units_sold << std::endl;
		}
		else
		{
				std::cerr << "No data?!" << std::endl;
				return -1;
		}
		return 0;
}
				
