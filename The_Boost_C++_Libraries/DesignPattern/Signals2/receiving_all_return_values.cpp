#include <boost/signals2.hpp>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace boost::signals2;

template <typename T>
struct min_element
{
		typedef T result_type;

		template <typename InputIterator>
		T operator()(InputIterator first, InputIterator last) const
		{
				return T(first, last);
		}
};

int main()
{
		signal<int(), min_element<std::vector<int>>> s;
		s.connect([] { return 1; });
		s.connect([] { return 2; });
		std::vector<int> v = s();
		std::cout << *std::min_element(v.begin(), v.end()) << '\n';
		return 0;
}
