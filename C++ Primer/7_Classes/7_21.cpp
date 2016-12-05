#include <iostream>
#include <string>
std::istream &read(std::istream &is, class Sales_data &item);

class Sales_data {
		friend std::istream& read(std::istream &is, class Sales_data&);
		friend std::ostream& print(std::ostream &os, class Sales_data&);
	public:
		std::string bookNo;
	private:
		unsigned units_sold = 0;
		double revenue = 0.0;
	public:
		Sales_data& combine(const Sales_data&);
		Sales_data(const std::string &s);
		Sales_data() = default;
		Sales_data(std::istream &is)
		{
				read(is, *this);
		}
};

std::istream &read(std::istream &is, class Sales_data &item)
{
		double price = 0;
		is >> item.bookNo >> item.units_sold >> price;
		item.revenue = price * item.units_sold;
		return is;
}

std::ostream& print(std::ostream &os, class Sales_data &item)
{
		std::cout << "count: " << item.units_sold << " each price: " << item.revenue / item.units_sold << std::endl;
		return os;
}

Sales_data::Sales_data(const std::string &s): bookNo(s)
{
		std::cout << "Outside" << std::endl;
		std::cout << "bookNo: " << bookNo << std::endl;
}

Sales_data& Sales_data::combine(const Sales_data& item)
{
		units_sold += item.units_sold;
		revenue += item.revenue;
		return *this;
}

int main()
{
		Sales_data total(std::cin), trans;
		while(read(std::cin, trans))
		{
				if (trans.bookNo == total.bookNo)
						total.combine(trans);
				else
				{
						print(std::cout, total);
						total = trans;
				}
		}
		print(std::cout, total);
		return 0;
}


