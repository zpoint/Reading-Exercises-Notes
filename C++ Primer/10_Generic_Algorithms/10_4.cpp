/*
 * Double will be converted to int
 */
#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
		std::vector<double> dvec{1.1, 2.2, 3.3, 4.4};
		std::cout << std::accumulate(dvec.cbegin(), dvec.cend(), 0) << std::endl;
		return 0;
}
