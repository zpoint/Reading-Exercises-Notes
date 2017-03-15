#include <iostream>
#include <functional>
#include <vector>

int main()
{
		std::modulus<int> mod;
		int i;
		std::vector<int> ivec{2, 4, 6, 8, 10};
		std::cout << "Enter an ineger: " << std::endl;
		std::cin >> i;
		auto func = std::bind(mod, std::placeholders::_1, i);
		for (const auto &item : ivec)
				if (func(item))
				{
						std::cout << "Not divisible by " << item << std::endl;
						return 0;
				}
		std::cout << "All divisible" << std::endl;
		return 0;
}
