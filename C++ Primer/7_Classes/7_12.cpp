#include <iostream>
#include <string>
std::istream &read(std::istream &is, struct Sales_data &item);

struct Sales_data {
		std::string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;
		Sales_data(const std::string &s);

		Sales_data(std::istream &is)
		{
				read(is, *this);
		}
};

std::istream &read(std::istream &is, struct Sales_data &item)
{
		double price = 0;
		is >> item.bookNo >> item.units_sold >> price;
		item.revenue = price * item.units_sold;
		return is;
}

Sales_data::Sales_data(const std::string &s): bookNo(s)
{
		std::cout << "Outside" << std::endl;
		std::cout << "bookNo: " << bookNo << std::endl;
}

int main()
{
		Sales_data s("123");
		return 0;
}


