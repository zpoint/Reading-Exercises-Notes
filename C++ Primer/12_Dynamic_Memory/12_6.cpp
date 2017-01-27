#include <vector>
#include <iostream>

std::vector<int> *create_vector_of_int()
{
		return new std::vector<int>;
}

void read_from_cin(std::vector<int> *ivec)
{
		int integer;
		while (std::cin >> integer)
				(*ivec).push_back(integer);
}

void pr_vector(std::vector<int> *ivec)
{
		for (const auto &item : *ivec)
				std::cout << item << " ";
		std::cout << std::endl;
}

int main()
{
		std::vector<int> *ivec_ptr = create_vector_of_int();
		read_from_cin(ivec_ptr);
		pr_vector(ivec_ptr);
		delete ivec_ptr;
		return 0;
}
