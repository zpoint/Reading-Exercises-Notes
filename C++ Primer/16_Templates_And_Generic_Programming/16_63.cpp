#include <iostream>
#include <vector>

template <typename T>
size_t occurence_count(std::vector<T>& tvec, const T&& val)
{
		size_t count = 0;
		for (const auto &item : tvec)
		{
				if (item == val)
						count += 1;
		}
		return count;
}

int main()
{
		std::vector<double> dvec = {1.1 , 2.2, 3.3, 4.4, 2.2, 5.5, 2.2, 2.2};
		std::vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 22, 11};
		std::vector<std::string> svec = {"123", "sdas", "123", "123", "fds"};
		std::cout << occurence_count(dvec, 2.2) << std::endl;
		std::cout << occurence_count(ivec, 11) << std::endl;
		std::cout << occurence_count(svec, std::string("123")) << std::endl;
		return 0;
}
