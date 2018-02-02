#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <map>

std::map<int, size_t> val_map;

void generate_to_file(unsigned long long max_val)
{
		std::ofstream ofs("temp.txt");
		for (unsigned long long i = 0; i < max_val; ++i)
				ofs << i << "\n";
		// 10 and 15 are two repeat value
		ofs << 10 << "\n";
		ofs << 15 << "\n";
		ofs.close();
}

struct BitSearch
{
		BitSearch(std::string filename, std::size_t pos, std::queue<std::pair<std::string, std::size_t>> &task_queue)
		{
				std::ostringstream os, os0, os1;
				os << pos;
				os0 << (pos - 1) << "_0_";
				os1 << (pos - 1) << "_1_";

				std::string filename_in = filename + ".txt";
				std::string filename_out_0 = filename + os0.str() + ".txt";
				std::string filename_out_1 = filename + os1.str() + ".txt";
				// std::cout << "filename_in: " << filename_in << std::endl;
				// std::cout << "filename_out_0: " << filename_out_0 << std::endl;
				// std::cout << "filename_out_1: " << filename_out_1 << std::endl;

				std::ifstream ifs(filename_in);
				std::ofstream ofs0(filename_out_0), ofs1(filename_out_1);

				int mask = 1 << (pos - 1);
				int val;
				while (ifs >> val)
				{
						if (val & mask)
						{
								if (pos == 1) // final file
										val_map[val] += 1;
								ofs1 << val << "\n";
						}
						else
						{
								if (pos == 1)
										val_map[val] += 1;
								ofs0 << val << "\n";
						}
				}
				
				ifs.close();
				// std::cout << "removing: " << filename_in.c_str() << std::endl;
				std::remove(filename_in.c_str());
				
				if (pos > 1)
				{
						pos -= 1;
						task_queue.push(std::make_pair(filename + os0.str(), pos));
						task_queue.push(std::make_pair(filename + os1.str(), pos));
				}
				else
				{
						// std::cout << "pos <= 1, filename_out_0: " << filename_out_0 << " filename_out_1: " << filename_out_1 << std::endl;
						ofs0.close();
						ofs1.close();
						std::remove(filename_out_0.c_str());
						std::remove(filename_out_1.c_str());
				}
		}
};

int main()
{
		std::cout << "generating temp file" << std::endl;
		generate_to_file(1<<5);
		std::cout << "generate done" << std::endl;
		std::queue<std::pair<std::string, std::size_t>> task_queue;
		task_queue.push(std::make_pair("temp", 6));
		while (!task_queue.empty())
		{
				std::pair<std::string, std::size_t> param = task_queue.front();
				task_queue.pop();
				BitSearch(param.first, param.second, task_queue);
		}
		for (auto &pair : val_map)
		{
				if (pair.second > 1)
						std::cout << pair.first << " repeat: " << pair.second << " time\n";
		}
		return 0;
}
