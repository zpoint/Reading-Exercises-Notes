#include <iostream>

struct Sales_data
{
		std::string ISBN;
		unsigned units_sold = 0;
		double revenue = 0.0;
};

int e1_21()
{
		Sales_data item1, item2;
		double price;
		std::cout << "Please imput two items in form \"ISBN units_sold price\"" << std::endl;
		std::cin >> item1.ISBN >> item1.units_sold >> price;
		item1.revenue = item1.units_sold * price;
		std::cin >> item2.ISBN >> item2.units_sold >> price;
		item2.revenue = item2.units_sold * price;

		unsigned total = item1.units_sold + item2.units_sold;
		double total_revenue = item1.revenue + item2.revenue;
		if (item1.ISBN == item2.ISBN)
		{
				std::cout << item1.ISBN << " ";
				if (total > 0)
						std::cout << total << " " << total_revenue / total << std::endl;
				else
						std::cout << "(no sales)" << std::endl;
		}
		else
				std::cerr << "Dtata must refer to same ISBN" << std::endl;
		return(1);
}

int e1_22()
{
		Sales_data item1, item2;
		double price;
		unsigned count = 1;
		std::cout << "Enter several items in form \"ISBN units_sold price\"" << std::endl;
		std::cin >> item1.ISBN >> item1.units_sold >> price;
		item2.ISBN = item1.ISBN;
		while (item2.ISBN == item1.ISBN)
		{
				++count;
				item1.revenue += item2.revenue;
				item1.units_sold += item2.units_sold;
				std::cin >> item2.ISBN >> item2.units_sold >> price;
				item2.revenue = item2.units_sold * price;
		}
		std::cout << "total: " << count << " inputs" << std::endl;
		std::cout << item1.ISBN << " " << item1.units_sold << " " << item1.revenue / item1.units_sold << std::endl;
		return(0);
}

int e1_23()
{
		Sales_data item1, item2;
		double price;
		unsigned count = 1;
		std::cout << "Enter several items in form \"ISBN units_sold price\", I will count each isbn" << std::endl;
		std::cin >> item1.ISBN >> item1.units_sold >> price;
		item1.revenue = item1.units_sold * price;
		while (std::cin >> item2.ISBN >> item2.units_sold >> price)
		{
				item2.revenue = item2.units_sold * price;
				if (item1.ISBN == item2.ISBN)
				{
						++count;
						item1.units_sold += item2.units_sold;
						item1.revenue += item2.revenue;
				}
				else
				{
						std::cout << "Count: " << count << " " << item1.ISBN << " " << item1.units_sold << " " << item1.revenue << std::endl;
						item1.ISBN = item2.ISBN;
						item1.units_sold = item2.units_sold;
						item1.revenue = item2.revenue;
						count = 1;
				}
		}
		return(1);
}



int main()
{
		e1_23();
		return(0);
}

