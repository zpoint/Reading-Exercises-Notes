#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <set>

class Quote
{
		public:
			Quote() { std::cout << "Calling default constructor of Quote" << std::endl; };
			Quote(const std::string &book, double sales_price):
					bookNo(book), price(sales_price) { std::cout << "Calling 4 paramters constrctor of Quote" << std::endl; }
			std::string isbn() const { return bookNo; }
			virtual double net_price(std::size_t n) const { return n * price; }
			virtual ~Quote() = default;
			virtual Quote* clone() const & { return new Quote(*this); }
			virtual Quote* clone() && { return new Quote(std::move(*this)); }
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
			virtual Bulk_quote* clone() const & override { return new Bulk_quote(*this); }
			virtual Bulk_quote* clone() && override { return new Bulk_quote(std::move(*this)); }
};

double Bulk_quote::net_price(std::size_t size) const
{
		std::cout << "Bulk_quote::net_price, size: " << size << std::endl;
	   return size * discount * price;
}	   

class Basket
{
		public:
			void add_item(const Quote& sale) { items.insert(std::shared_ptr<Quote>(sale.clone())); }
			void add_item(Quote&& sale) { items.insert(std::shared_ptr<Quote>(std::move(sale).clone())); }
			double total_receipt(std::ostream&) const;
		private:
			static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) { return lhs->isbn() < rhs->isbn(); }
			std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};

double Basket::total_receipt(std::ostream &os) const
{
		os << "tptal_receipt" << std::endl;
		double sum = 0;
		for (const auto &iter : items)
				sum += iter->net_price(5);
	   os << "Sum: " << sum << std::endl;	
		return sum;
}

int main()
{
		Basket b;
		Bulk_quote d("das", 30, 10, 20);
		Bulk_quote d2("ddd", 20, 10, 15);
		b.add_item(d);
		b.add_item(d2);
		b.total_receipt(std::cout);
		return 0;
}
