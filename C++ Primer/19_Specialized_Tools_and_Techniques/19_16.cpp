#include <iostream>

class Sales_data
{
		public:
			double avg_price(int i) 
			{ return (double)i; }
};

int main()
{
		using AVG = double (Sales_data::*) (int);
		AVG avg = &Sales_data::avg_price;
		Sales_data s;
		std::cout << (s.*avg)(3) << std::endl;
		return 0;
}
