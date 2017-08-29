#include <iostream>
#include <string>

class Sales_data
{
		public:
			std::string bookNo;
};

int main()
{
		std::string Sales_data::*bookNo_ptr;
		Sales_data s;
		bookNo_ptr = &Sales_data::bookNo;
		std::cout << s.*bookNo_ptr << std::endl;
		return 0;
}
