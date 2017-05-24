#include <iostream>
#include <vector>

template <typename T>
size_t occurence_count(std::vector<T>& tvec, T val)
{
		size_t count = 0;
		for (const auto &item : tvec)
		{
				if (item == val)
						count += 1;
		}
		return count;
}

template <>
size_t occurence_count(std::vector<const char *> &tvec, const char* val)
{
		
		size_t count = 0;
		char* tmp_ptr;
		for (auto char_ptr : tvec)
		{
				tmp_ptr = const_cast<char *>(val);
				while (*char_ptr != '\0' and *tmp_ptr != '\0' and *char_ptr++ == *tmp_ptr++);
				if (*char_ptr == *tmp_ptr)
						count += 1;
		}
		return count;
}

int main()
{
		std::vector<double> dvec = {1.1 , 2.2, 3.3, 4.4, 2.2, 5.5, 2.2, 2.2};
		std::vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 22, 11};
		std::vector<std::string> svec = {"123", "sdas", "123", "123", "fds"};
		std::vector<const char *> cvec = {"345", "345", "345", "dsad", "dsad", "345", "345", "345"};
		std::cout << occurence_count(dvec, 2.2) << std::endl;
		std::cout << occurence_count(ivec, 11) << std::endl;
		std::cout << occurence_count(svec, std::string("123")) << std::endl;
		std::cout << occurence_count(cvec, "345") << std::endl;
		return 0;
}
