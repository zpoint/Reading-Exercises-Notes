#include <string>
#include <iostream>

class Sales_data {
		public:
			Sales_data(std::string isbn_=""): ISBN(isbn_) { }
			std::string ISBN;
			std::string isbn() const { return this->ISBN; }

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

int main()
{
		Sales_data item1("item1");
		std::cout << item1;
		std::cin >> item1;
		std::cout << item1;
		return 0;
}
