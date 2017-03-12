#include <string>
#include <iostream>

class Sales_data {
		public:
			Sales_data(std::string isbn_=""): ISBN(isbn_) { }
			std::string ISBN;
			std::string isbn() const { return this->ISBN; }
			Sales_data operator+(const Sales_data &) const;
			Sales_data &operator+=(const Sales_data &);
};
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
		return lhs.isbn() < rhs.isbn();
}

std::istream &operator>>(std::istream &is, Sales_data &item)
{
		std::cout << "Calling operator >>" << std::endl;
		is >> item.ISBN;
		return is;
}

std::ostream &operator<<(std::ostream &os, Sales_data &item)
{
		std::cout << "Calling operator <<" << std::endl;
		os << item.ISBN << std::endl;
		return os;
}

Sales_data Sales_data::operator+(const Sales_data &item2) const
{
		std::cout << "calling operator +" << std::endl;
		if (ISBN != item2.ISBN)
				throw std::runtime_error("Unable to execute operator +, ISBN mismatch");
		Sales_data new_data(item2.ISBN);
		return new_data;
}

Sales_data& Sales_data::operator+=(const Sales_data &item2)
{
		std::cout << "calling operator += " << std::endl;	
		if (ISBN != item2.ISBN)
				throw std::runtime_error("Unable to execute operator +, ISBN mismatch");
		return *this;
}

int main()
{
		Sales_data item1("item1"), item2;
		std::cout << item1;
		std::cin >> item1;
		std::cout << item1;
		item2 = item1;
		item2 += item1;
		item2 + item1;
		return 0;
}
