#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

template <typename T1, typename T2>
struct fopow
{
		T1 operator() (T1 base, T2 exp) const 
		{
				return std::pow(base, exp);
		}
};


int main()
{
		std::vector<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		// print 3 raised to the power of all elements
		std::transform(coll.begin(), coll.end(), std::ostream_iterator<float>(std::cout, " "), std::bind(fopow<float, int>(), 3, std::placeholders::_1));
		std::cout << std::endl;

		// print all elements raised to the power of 3
		std::transform(coll.begin(), coll.end(), std::ostream_iterator<float>(std::cout, " "), std::bind(fopow<float, int>(), std::placeholders::_1, 3));
		std::cout << std::endl;

		return 0;
}
