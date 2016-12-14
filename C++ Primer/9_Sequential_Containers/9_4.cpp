#include <vector>
#include <iostream>

bool search_in_vector(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, const int val)
{
		while (begin != end)
		{
				if (*begin == val)
						return true;
				++begin;
		}
		return false;
}


int main()
{
		std::vector<int> ivec{1,2,3,4,5,6,7,8}, i2vec{1,2,3,4,5,7,8,9,0};
		std::cout << search_in_vector(ivec.begin(), ivec.end(), 6) << std::endl;
		std::cout << search_in_vector(i2vec.begin(), i2vec.end(), 6) << std::endl;
		return 0;
}
