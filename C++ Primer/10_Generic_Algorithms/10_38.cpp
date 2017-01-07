#include <iostream>
#include <vector>

void ordinary_pr(const std::vector<int> &ivec, std::vector<int>::iterator iter)
{
		std::vector<int>::iterator curr_iter = iter;
		if (iter != ivec.end())
		{
				ordinary_pr(ivec, ++iter);
				std::cout << *curr_iter << " ";
		}
}


int main()
{
		std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
		ordinary_pr(ivec, ivec.begin());
		std::cout << std::endl;
		return 0;
}
