#include <iostream>
#include <string>
#include <random>

int main()
{
		std::string resp;
		do
		{
				std::default_random_engine e;
				std::bernoulli_distribution b;
				// first will always be same result
				bool first = b(e);
				std::cout << (first ? "We go first" : "You get to go first") << std::endl;
				std::cout << "play again? Enter 'yes' or 'no'" << std::endl;
		} while (std::cin >> resp && resp[0] == 'y');
		return 0;
}
