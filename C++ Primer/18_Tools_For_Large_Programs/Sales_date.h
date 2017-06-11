#include <iostream>
#include <string>
#include <exception>


std::istream &read(std::istream &is, struct Sales_data &item);

struct Sales_data {
		friend struct std::hash<Sales_data>;
		std::string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;
		Sales_data& combine(const Sales_data&);
		Sales_data(const std::string &s);
		Sales_data() = default;
		Sales_data(std::istream &is)
		{
				read(is, *this);
		}
		Sales_data &operator+=(const Sales_data&);
		bool operator==(const Sales_data&) const;
		bool operator<(const Sales_data&) const;
};

class isbn_mismatch: public std::logic_error
{
		public:
			explicit isbn_mismatch(const std::string &err, const std::string &lhs, const std::string &rhs): std::logic_error(err), left(lhs), right(rhs) {std::cout << "isbn_mismatch constructor" << std::endl;}
			std::string left;
			std::string right;
};

std::istream &read(std::istream &is, struct Sales_data &item)
{
		double price = 0;
		is >> item.bookNo >> item.units_sold >> price;
		item.revenue = price * item.units_sold;
		return is;
}

std::ostream& print(std::ostream &os, struct Sales_data &item)
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

std::ostream& operator<<(std::ostream &os, const Sales_data &item)
{
		os << item.bookNo << " " << item.units_sold << " " << item.revenue << std::endl;
		os << item.units_sold << " " << item.revenue << " " << item.bookNo;
		return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
		if (lhs.bookNo != rhs.bookNo)
				throw isbn_mismatch("wrong isbn", lhs.bookNo, rhs.bookNo);
		Sales_data item = lhs;
		item.combine(rhs);
		return item;
}

Sales_data& Sales_data::operator+=(const Sales_data &item)
{
		if (bookNo != item.bookNo)
				throw isbn_mismatch("wrong isbns", bookNo, item.bookNo);
		Sales_data sd = *this + item;
		*this = sd;
		return *this;
}

bool Sales_data::operator==(const Sales_data &item) const
{
		return item.bookNo == bookNo;
}

bool Sales_data::operator<(const Sales_data &item) const
{
		return bookNo < item.bookNo;
}

std::istream& operator>>(std::istream &is, Sales_data &item)
{
		is >> item.bookNo;
		return is;
}
