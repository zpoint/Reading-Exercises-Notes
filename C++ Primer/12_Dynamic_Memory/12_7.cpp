#include <vector>
#include <iostream>
#include <memory>

std::shared_ptr<std::vector<int>> create_vector_of_int()
{
		std::shared_ptr<std::vector<int>> ivec_ptr = std::make_shared<std::vector<int>>();
		return ivec_ptr;
}

void read_from_cin(std::shared_ptr<std::vector<int>> ivec)
{
		int integer;
		while (std::cin >> integer)
				(*ivec).push_back(integer);
}

void pr_vector(std::shared_ptr<std::vector<int>> ivec)
{
		for (const auto &item : *ivec)
				std::cout << item << " ";
		std::cout << std::endl;
}

int main()
{
		std::shared_ptr<std::vector<int>> ivec_ptr = create_vector_of_int();
		read_from_cin(ivec_ptr);
		pr_vector(ivec_ptr);
		std::cout << "ivec_ptr.use_count(): " << ivec_ptr.use_count() << std::endl;
		return 0;
}
