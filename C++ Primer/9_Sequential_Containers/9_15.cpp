#include <iostream>
#include <vector>

void pr_vec(const std::vector<int> vec, const char *str)
{
		std::cout << str << ": ";
		for (const auto i : vec)
				std::cout << i << " ";
		std::cout << std::endl;
}

int main()
{
		std::vector<int> ivec1{1, 2, 3}, ivec2{1, 3};
		pr_vec(ivec1, "ivec1");
		pr_vec(ivec2, "ivec2");
		std::cout << "ivec1 ";
		if (ivec1 == ivec2)
				std::cout << "=";
		else if (ivec1 < ivec2)
				std::cout << "<";
		else if (ivec1 > ivec2)
				std::cout << ">";
		else
				std::cout << "Unknown";
		std::cout << " ivec2" << std::endl;
		return 0;
}

