#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

int main(int argc, char **argv)
{
		if (argc != 2)
				throw std::runtime_error("Usage: program_name filename");

		std::ifstream infile(argv[1]);
		if (!infile)
				throw std::runtime_error("Unable to open file" + std::string(argv[1]));
		std::vector<std::pair<std::string, std::size_t>> pair_vec;
		std::size_t index = 0;
		std::vector<std::string> vec_str;
		std::string buffer;
		while (std::getline(infile, buffer))
				vec_str.push_back(buffer);
		while (true)
		{
				std::cout << "Enter string to search: (q to quit)" << std::endl;
				std::cin.clear();
				std::cin >> buffer;
				if (buffer == "q")
						break;
				for (const auto &str : vec_str)
				{
						index += 1;
						if (str.find(buffer) != std::string::npos)
								pair_vec.push_back(std::make_pair(buffer, index));
				}
				std::sort(pair_vec.begin(), pair_vec.end(), [](std::pair<std::string, std::size_t> pair1, std::pair<std::string, std::size_t> pair2){ return pair1.second < pair2.second; });
				if (pair_vec.size())
				{
						for (const auto &pair : pair_vec)
								std::cout << "line: (" << pair.second << ") " << pair.first << "\r\n";
				}
				else
						std::cout << "No result!!!!!" << std::endl;
		}

		return 0;
}
