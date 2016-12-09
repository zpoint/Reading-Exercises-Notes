#include <iostream>
#include <string>
std::istream &read(std::istream &is, class Sales_data &item);

class Sales_data {
		friend std::istream& read(std::istream &is, class Sales_data&);
		friend std::ostream& print(std::ostream &os, class Sales_data&);
	public:
		inline double avg_price() { return revenue ? revenue / units_sold : revenue; }
		std::string bookNo;
	private:
		unsigned units_sold = 0;
		double revenue = 0.0;
	public:
		Sales_data& combine(const Sales_data&);

		Sales_data(std::string s, unsigned cnt, double price): bookNo(s), units_sold(cnt), revenue(price * cnt) {
				std::cout << "Calling 3 paramaters constructor, s: " << s << " cnt: " << cnt << " price: " << price << std::endl;
		}

		Sales_data(const std::string &s);
		Sales_data(): Sales_data("", 0, 0) { std::cout << "Calling default constructor" << std::endl; }
		Sales_data(std::istream &is): Sales_data()
		{
				std::cout << "One paramaters initialized, Is stream, calling read" << std::endl;
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

Sales_data::Sales_data(const std::string &s): Sales_data(s, 0, 0)
{
		std::cout << "One paramaters constructor, s: " << bookNo << std::endl;
}

Sales_data& Sales_data::combine(const Sales_data& item)
{
		units_sold += item.units_sold;
		revenue += item.revenue;
		return *this;
}

int main()
{
		Sales_data total(std::cin), trans, tmp("123");
		print(std::cout, total);
		return 0;
}


