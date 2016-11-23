#include <iostream>
#include <vector>
#include <string>

void pr_rec(std::vector<int> ivec, std::vector<int>::const_iterator iter)
{
		if (iter != ivec.end())
		{
				std::cout << *iter << std::endl;
				pr_rec(ivec, ++iter);
		}
}

int main()
{
		std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		std::string str = "0123456789"
		for (auto i = ivec.cbegin(); i != ivec.cend(); ++i)
				std::cout << *i << std::endl;
		//std::cout << "Calling pr_rec(ivec, ivec.cbegin()): " << std::endl;
		pr_rec(ivec, ivec.begin());
		return 0;
}	
