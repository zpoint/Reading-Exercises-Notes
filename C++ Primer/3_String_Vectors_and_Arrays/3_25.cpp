#include <iostream>
#include <string>
#include <vector>

int main()
{
		std::vector<unsigned> scores(11, 0);
		unsigned grade;
		while (std::cin >> grade)
				if (grade <= 100)
						++*(scores.begin() + (grade / 10));
		for (auto i = scores.begin(); i != scores.end(); ++i)
				std::cout << *i << " ";
		std::cout << std::endl;
		return(0);
}
