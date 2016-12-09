#include <iostream>
#include <string>

using std::string;

class Sales_data {
		public:
				Sales_data(std::string s = "default bookNo"): bookNo(s) { }
				Sales_data(std::string s, unsigned cnt, double rev):
						bookNo(s), units_sold(cnt), revenue(rev*cnt) { }
				string bookNo;
				unsigned units_sold;
				double revenue;
};


int main()
{
		Sales_data next;
		std::cout << "BookNo for next: " << next.bookNo << "\n";
		Sales_data last("9-999-99999-9");
		std::cout << "BookNo for last: " << last.bookNo << std::endl;
		return 0;
}
