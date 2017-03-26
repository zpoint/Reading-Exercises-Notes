#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Quote
{
		public:
			Quote() { std::cout << "Calling default constructor of Quote" << std::endl; };
			Quote(const std::string &book, double sales_price):
					bookNo(book), price(sales_price) { std::cout << "Calling 4 paramters constrctor of Quote" << std::endl; }
			std::string isbn() const { return bookNo; }
			virtual double net_price(std::size_t n) const { return n * price; }
			virtual ~Quote() = default;
		private:
			std::string bookNo;
		protected:
			double price = 0.0;
};

class Disc_quote : public Quote
{
		public:
			Disc_quote() = default;
			Disc_quote(const std::string& book, double price, std::size_t qty, double disc):
					Quote(book, price), quantity(qty), discount(disc) { }
			double net_price(std::size_t) const = 0;
		protected:
			std::size_t quantity = 0;
			double discount = 0.0;
};

class Bulk_quote : public Disc_quote
{
		public:
			using Disc_quote::Disc_quote;
			double net_price(std::size_t) const override;
};

double Bulk_quote::net_price(std::size_t size) const
{
		std::cout << "Bulk_quote::net_price, size: " << size << std::endl;
	   return size * discount * price;
}	   

int main()
{
		std::vector<Quote *> quote_vec;
		Bulk_quote d("das", 30, 10, 20);
		Bulk_quote d2("ddd", 20, 10, 15);
		quote_vec.push_back(&d);
		quote_vec.push_back(&d2);
		std::cout << "Push Done" << std::endl;
		double sum = 0;
		for (const auto &ptr : quote_vec)
				sum += ptr->net_price(quote_vec.size());
		std::cout << "Sum: " << sum << std::endl;
		return 0;
}
