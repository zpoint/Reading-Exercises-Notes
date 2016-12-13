#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cassert>

int main(int argc, char *argv[])
{
		assert(argc == 2);
		std::vector<std::string> svec;
		std::string buffer;
		std::ifstream fis(argv[1]);
		while (std::getline(fis, buffer))
				svec.push_back(buffer);

		std::istringstream istring;
		for (auto i : svec)
		{
				std::istringstream istring(i);
				while (istring >> buffer)
						std::cout << buffer << "\n";
		}
		return 0;
}
