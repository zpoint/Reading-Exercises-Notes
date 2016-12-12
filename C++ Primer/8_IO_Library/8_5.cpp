#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main()
{
		std::vector<std::string> svec;
		std::ifstream fs("fail.txt");
		std::string line;
		while (fs)
		{
				std::getline(fs, line);
				svec.push_back(line);
		}

		for (auto i : svec)
				std::cout << i << "\n";
		return 0;
}
