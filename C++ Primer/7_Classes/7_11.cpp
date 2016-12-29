#include <iostream>
#include <string>
struct Sales_data {
		std::string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;
		Sales_data(const std::string &s);
};

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


