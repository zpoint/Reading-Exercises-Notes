#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

class Sales_data
{
		public:
			Sales_data(double d): avg_price(d) { }
			double avg_price;
};

bool greater(const Sales_data& lhs, double amount)
{
		return lhs.avg_price > amount;
}

int main()
{
		std::vector<Sales_data> S_vec = {3.3, 4.4, 6.0, 8.5, 4.3};
		auto f = std::bind(greater, std::placeholders::_1, 6.0);
		std::vector<Sales_data>::iterator iter = std::find_if(S_vec.begin(), S_vec.end(), f);
		if (iter != S_vec.end())
				std::cout << "Find: " << iter->avg_price << std::endl;
		return 0;
}
