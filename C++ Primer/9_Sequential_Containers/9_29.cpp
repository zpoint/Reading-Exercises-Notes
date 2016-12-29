#include <vector>
#include <iostream>

void pr_ivec(const std::vector<int> &ivec, std::string str = "")
{
		std::vector<int>::size_type count = 0;
		if (str != "")
				std::cout << str << std::endl;
		for (const auto i : ivec)
		{
				std::cout << i << " ";
				if (count % 10 == 0 and count != 0)
						std::cout << "\n";
		}
		std::cout << "\n";
}


int main()
{
		std::vector<int> ivec(25, 1);
		pr_ivec(ivec, "Before Resize");
		ivec.resize(100);
		pr_ivec(ivec, "Resize 100:");
		ivec.resize(10);
		pr_ivec(ivec, "Resize 10");
		return 0;
}
