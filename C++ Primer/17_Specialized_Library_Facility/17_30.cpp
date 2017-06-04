#include <iostream>
#include <random>

int random_generate(std::uniform_int_distribution<int> dist)
{
		static std::default_random_engine e;
		return dist(e);
}

int main()
{
		std::string buffer;
		int min, max;
		std::cout << "Enter a min and a max, I will generator a random number each time by your range" << std::endl;
		std::cin >> min >> max;
		std::uniform_int_distribution<int> dist(min, max);
		while (std::getline(std::cin, buffer))
				std::cout << random_generate(dist) << std::endl;
		return 0;
}
