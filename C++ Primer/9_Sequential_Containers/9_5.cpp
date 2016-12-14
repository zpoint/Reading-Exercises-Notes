#include <vector>
#include <iostream>

std::vector<int>::const_iterator search_in_vector(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, const int val)
{
		while (begin != end)
		{
				if (*begin == val)
						return begin;
				++begin;
		}
		return end;
}


int main()
{
		std::vector<int> ivec{1,2,3,4,5,6,7,8}, i2vec{1,2,3,4,5,7,8,9,0};
		std::vector<int>::const_iterator iterator;
		iterator = search_in_vector(ivec.begin(), ivec.end(), 6);
		if (iterator == ivec.cend())
				std::cout << "Not found in ivec" << "\n";
		else
				std::cout << "Found: " << *iterator << "\n";

		iterator = search_in_vector(i2vec.begin(), i2vec.end(), 6);
		if (iterator == i2vec.cend())
				std::cout <<  "Not found in i2vec" << std::endl;
		else
				std::cout << "Found: " << *iterator << std::endl;
		return 0;
}
