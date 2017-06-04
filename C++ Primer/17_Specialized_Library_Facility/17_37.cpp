#include <iostream>
#define MAX_LINE 8

int main()
{
		char line[MAX_LINE];
		while (std::cin.getline(line, MAX_LINE))
		{
				const int sz = std::cin.gcount();
				std::cout << std::endl << "gcount(): " << sz << std::endl;
				std::cout.write(line, sz);
		}
		std::cout << std::endl;
		return 0;
}
