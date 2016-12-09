#include <iostream>
#include <string>

using std::string;

class Sales_data {
		public:
				Sales_data(std::string s = ""): bookNo(s) { }
				Sales_data(std::string s, unsigned cnt, double rev):
						bookNo(s), units_sold(cnt), revenue(rev*cnt) { }
				string bookNo;
				Sales_data (std::istream &is = std::cin) { is >> bookNo >> units_sold >> revenue; }
				unsigned units_sold; 
				double revenue;
};


int main()
{
		/*
		 * Leagal, But can't use a default constructor, Because it's ambigious
		 */
		Sales_data next("123");
		std::cout << "BookNo for next: " << next.bookNo << "\n";
		Sales_data last("9-999-99999-9");
		std::cout << "BookNo for last: " << last.bookNo << std::endl;
		return 0;
}
