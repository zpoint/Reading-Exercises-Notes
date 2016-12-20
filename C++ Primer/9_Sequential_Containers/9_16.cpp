#include <iostream>
#include <vector>
#include <list>

void pr_vec(const std::vector<int> vec, const char *str)
{
		std::cout << str << ": ";
		for (const auto i : vec)
				std::cout << i << " ";
		std::cout << std::endl;
}

void pr_list(const std::list<int> vec, const char *str)
{
		std::cout << str << ": ";
		for (const auto i : vec)
				std::cout << i << " ";
		std::cout << std::endl;
}

int main()
{
		std::vector<int> ivec1{1, 2, 3};
		std::list<int> li{1, 3};
		pr_vec(ivec1, "ivec1");
		pr_list(li, "li");
		std::cout << "ivec1 ";

		char judge = 0;
		auto vec_iterator = ivec1.cbegin();
		for (auto li_iterator = li.cbegin(); li_iterator != li.cend() && vec_iterator != ivec1.cend() ; ++li_iterator, ++vec_iterator)
		{
				if (*vec_iterator > *li_iterator)
				{
						judge = '>';
						break;
				}
				else if (*vec_iterator < *li_iterator)
				{
						judge = '<';
						break;
				}
		}
		if (!judge)
		{
				if (ivec1.size() > li.size())
						judge = '>';
				else if (ivec1.size() < li.size())
						judge = '<';
				else
						judge = '=';
		}

		std::cout << judge;
		std::cout << " li" << std::endl;
		return 0;
}

