#include <iostream>
#include <string>

class Quote
{
		public:
			Quote() { std::cout << "Calling default constructor of Quote" << std::endl; };
			Quote(const std::string &book, double sales_price):
					bookNo(book), price(sales_price) { std::cout << "Calling 4 paramters constrctor of Quote" << std::endl; }
			std::string isbn() const { return bookNo; }
			virtual double net_price(std::size_t n) const { return n * price; }
			virtual ~Quote() = default;
			virtual void debug()
			{
					std::cout << "Quote: bookNo: " << bookNo << " price: " << price << std::endl;
			}
		private:
			std::string bookNo;
		protected:
			double price = 0.0;
};

class Bulk_quote : public Quote
{
		public:
			Bulk_quote() { std::cout << "Default constructor of Bulk_quote" << std::endl; };
			Bulk_quote(const std::string& book, double p,
							std::size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) { }
			double net_price(std::size_t) const override;
			void debug() override
			{
					std::cout << "Bulk_quote:  price: " << price << " min_qty: " << min_qty << " discount: " << discount << std::endl;
			}

		private:
			std::size_t min_qty = 0;
			double discount = 0.0;
};

double Bulk_quote::net_price(std::size_t cnt) const
{
		if (cnt >= min_qty)
				return cnt * (1 - discount) * price;
		else
				return cnt * price;
}

class Limit_quote : public Quote
{
		public:
			Limit_quote() { std::cout << "DEfault constructor of Limit_quote" << std::endl; }
			Limit_quote(const std::string& book, double p, std::size_t lim, double disc): 
					Quote(book, p), limit(lim), discount(disc) { std::cout << "Constructor of Limit_quote" << std::endl; }
			double net_price(std::size_t n) const override
			{
					if (n > limit)
							return limit * price * discount + (n - limit) * price;
					else
							return n * price * discount;
			}
			void debug() override
			{
					std::cout << "Limit_quote price: " << price << " limit: " << limit << " discount: " << discount << std::endl;
			}
		private:
			std::size_t limit = 0;
			double discount = 0.0;
};

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
		double ret = item.net_price(n);
		os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
		return ret;
}

int main()
{
		Limit_quote lq("Limit_quote", 20, 3, 0.5);
		Quote q("Quote", 5);
		Quote *ptr_q = &q;
		ptr_q->debug();
		ptr_q = &lq;
		ptr_q->debug();
		return 0;
}
