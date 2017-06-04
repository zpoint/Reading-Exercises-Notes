#include <iostream>
#include <random>

unsigned int random_generate()
{
		static std::default_random_engine e;
		return e();
}

int main()
{
		std::string buffer;
		std::cout << "Enter something, I will generator a random number each time" << std::endl;
		while (std::getline(std::cin, buffer))
				std::cout << random_generate() << std::endl;
		return 0;
}
