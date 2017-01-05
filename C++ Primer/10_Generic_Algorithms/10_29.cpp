#include <vector>
#include <iterator>
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>

int main(int argc, char **argv)
{
		assert (argc == 2);
		std::ifstream fin(argv[1]);
		std::istream_iterator<std::string> iterator_in(fin), end;
		std::vector<std::string> svec;
		while (iterator_in != end)
				svec.push_back(*iterator_in++);
		for (const auto &i : svec)
				std::cout << i << " ";
		std::cout << std::endl;
		return 0;
}
