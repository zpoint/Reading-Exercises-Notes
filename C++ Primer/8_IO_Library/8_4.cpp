#include <fstream>
#include <iostream>
#include <string>

int main()
{
		std::ifstream fs("fail.txt");
		std::string line;
		while (fs)
		{
				std::getline(fs, line);
				std::cout << line << "\n";	
		}
		return 0;
}
