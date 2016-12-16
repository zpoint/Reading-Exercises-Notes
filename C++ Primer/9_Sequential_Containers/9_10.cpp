#include <iostream>
#include <vector>

int main()
{
		std::vector<int> v1; // vector<int>
		const std::vector<int> v2; // const vector<int>
		auto it1 = v1.begin(); // it1 ===> vector<int>::iterator 
		auto it2 = v2.begin(); // it2 ===> vector<int>::const_iterator
		auto it3 = v1.cbegin(), it4 = v2.cbegin(); // it3 ===> const_iterator, it4 same as it3
		return 0;
}
