#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void pr_vector(const std::vector<int> ivec, const std::string str = "")
{
		if (str != "")
				std::cout << str << std::endl;
		for (const auto i : ivec)
				std::cout << i << " ";
		std::cout << std::endl;
}


void elimDups(std::vector<int> &ivec)
{
		pr_vector(ivec, "Before Operation");
		sort(ivec.begin(), ivec.end());
		pr_vector(ivec, "After called sort");
		auto end_unique = unique(ivec.begin(), ivec.end());
		pr_vector(ivec, "After called unique");
		ivec.erase(end_unique, ivec.end());
		pr_vector(ivec, "After called erase");
}

int main()
{
		std::vector<int> ivec = {7,6,5,8,9,3,2,5,4,1};
		elimDups(ivec);
		return 0;
}
