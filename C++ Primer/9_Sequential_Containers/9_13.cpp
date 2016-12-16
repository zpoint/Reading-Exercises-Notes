#include <iostream>
#include <list>
#include <vector>

int main()
{
		std::list<int> l1{1, 2, 3, 4, 5};
		std::vector<int> v1{1, 2, 3, 4, 5};
		std::vector<double> v2(l1.cbegin(), l1.cend());
		std::vector<double> v3(v1.cbegin(), v1.cend());
		return 0;
}
