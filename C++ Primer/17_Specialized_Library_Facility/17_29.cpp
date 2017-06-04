#include <iostream>
#include <random>

unsigned int random_generate(std::default_random_engine e)
{
		return e();
}

int main()
{
		std::string buffer;
		unsigned seed;
		std::cout << "Enter a seed, I will generator a random number each time by your seed" << std::endl;
		std::cin >> seed;
		std::default_random_engine e(seed);
		while (std::getline(std::cin, buffer))
				std::cout << random_generate(e) << std::endl;
		return 0;
}
