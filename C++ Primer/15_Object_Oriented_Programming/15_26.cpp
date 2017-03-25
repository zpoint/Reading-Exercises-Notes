#include <string>
#include <iostream>
#include <utility>
#include <vector>

class Quote
{
		public:
			Quote() { std::cout << "Calling default constructor of Quote" << std::endl; };
			Quote(const std::string &book, double sales_price):
					bookNo(book), price(sales_price) { std::cout << "Calling 4 paramters constrctor of Quote" << std::endl; }
			Quote(const Quote &rhs): bookNo(rhs.bookNo), price(rhs.price) { std::cout << "copy constructor of Quote" << std::endl;} // copy constructor
			Quote(const Quote &&rhs) noexcept: bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price)) { std::cout << "move constructor of Quote" << std::endl; } // move constructor
			Quote& operator=(const Quote &rhs) { bookNo = rhs.bookNo; price = rhs.price; std::cout << "Copy assign of Quote" << std::endl; return *this; }
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
			Disc_quote(const Disc_quote &rhs): Quote(rhs), quantity(rhs.quantity), discount(rhs.discount) { std::cout << "copy constructor of Disc_quote" << std::endl; }
			Disc_quote(const Disc_quote &&rhs) noexcept: Quote(std::move(rhs)), quantity(std::move(rhs.quantity)), discount(std::move(rhs.discount)) { std::cout << "move constructor of Disc_quote" << std::endl; }
			Disc_quote& operator=(const Disc_quote &rhs) { Quote::operator=(rhs); quantity = rhs.quantity; discount = rhs.discount; std::cout << "copy assign of Disc_quote" << std::endl; return *this;}
			double net_price(std::size_t) const { return 0;};
		protected:
			std::size_t quantity = 0;
			double discount = 0.0;
};


int main()
{
		Disc_quote d;
		
		std::vector<Disc_quote> dq_vec;
		std::cout << "Going to push back" << std::endl;
		dq_vec.push_back(d);
		std::cout << "Push back again" << std::endl;
		dq_vec.push_back(d);
		std::cout << "Vector operation Done" << std::endl;
		d = dq_vec[0];
		
		return 0;
}
