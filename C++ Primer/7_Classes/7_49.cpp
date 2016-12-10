#include <iostream>
#include <string>

using std::string;
class Sales_data;

class Sales_data {
		public:
				Sales_data() { std::cout << "Default constructor" << std::endl; };
				Sales_data(const string &s, unsigned n, double p):
						bookNo(s), units_sold(n), revenue(n*p){ std::cout << "Full paramaters constructors" << std::endl; }
				Sales_data(const string &s): bookNo(s) { std::cout << "One paramater constructor, String: " << s << std::endl; }
				Sales_data(std::istream &is) { std::cout << "One paramater constructor, cin" << std::endl; }

				Sales_data &combine1(Sales_data d) {std::cout << "combine 1!, paramater: Sales_data" << std::endl; return *this; }
				Sales_data &combine2(Sales_data& d) {std::cout << "combine 2!, paramater: Sales_data&" << std::endl; return *this; }
				Sales_data &combine3(const Sales_data& d) {std::cout << "combine 3! paramater: const Sales_data&" << std::endl; return *this; }
 
		private:
						string bookNo;
						unsigned units_sold;
						double revenue;
};

int main()
{
		Sales_data s, d;
		std::string str("I am string");
		s.combine1(str);
		s.combine2(d);
		s.combine3(str);
		return 0;
}
