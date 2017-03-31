#include <iostream>
#include <vector>

template <typename T> void pr_container(T& container)
{
		for (const auto &item : container)
				std::cout << item << " ";
		std::cout << std::endl;
}

int main()
{
		std::vector<int> ivec{1, 2, 3, 4};
		pr_container(ivec);
		return 0;
}
