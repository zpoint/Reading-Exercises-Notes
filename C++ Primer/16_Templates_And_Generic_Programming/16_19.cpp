#include <iostream>
#include <vector>

template <typename T> void pr_container(T& container)
{
		for (typename T::size_type index = 0; index < container.size(); ++index)
				std::cout << container[index] << " ";
		std::cout << std::endl;
}

int main()
{
		std::vector<int> ivec{1, 2, 3, 4};
		pr_container(ivec);
		return 0;
}
