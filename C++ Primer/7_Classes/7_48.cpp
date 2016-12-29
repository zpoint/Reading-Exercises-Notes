#include <iostream>
#include <string>

using std::string;

class Sales_data {
		public:
				Sales_data() = default;
				Sales_data(const string &s, unsigned n, double p):
						bookNo(s), units_sold(n), revenue(n*p) { }
				explicit Sales_data(const string &s): bookNo(s) { }
				Sales_data(std::istream &is) { is >> bookNo >> units_sold >> revenue; }
 
		private:
						string bookNo;
						unsigned units_sold;
						double revenue;
};

int main()
{
		string null_isbn("9-999-99999-9");
		Sales_data item1(null_isbn);
		Sales_data item2("9-999-99999-9");
		return 0;
}
