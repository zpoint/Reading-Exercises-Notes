#include <iostream>
#include <vector>

int main()
{
		// insert every two steps, curr may invalid if reallocate space
		// warning, this code will cause undefined result
		std::vector<int> ivec(10 ,1);
		std::vector<int>::iterator curr = ivec.begin();
		while (curr != ivec.end())
		{
				std::cout << "Before operation:" << std::endl;
				std::cout << "curr: " << *curr << std::endl;
				for (const auto i : ivec)
						std::cout << i << " ";
				std::cout << std::endl;
				++curr;
				ivec.insert(curr, 42);
				++curr;
				std::cout << "After operation:" << std::endl;
				std::cout << "curr: " << *curr << std::endl;
				for (const auto i : ivec)
						std::cout << i << " ";
				std::cout << std::endl;
		}
		return 0;
}
