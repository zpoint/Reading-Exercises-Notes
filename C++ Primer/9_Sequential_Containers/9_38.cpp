#include <vector>
#include <string>
#include <iostream>

int str_to_int(std::string str)
{
		// should not exceed max_int
		std::string::size_type length = str.size();
		int val = 0;
		for (const auto i : str)
		{
				int digit = i - '0';
				int base_ten = length;
				int pos_val = 1;
				if (digit >= 10 || digit < 0)
				{
					// throw exceptions here	
				}
				while (--base_ten > 0)
						pos_val *= 10;
				val += pos_val * digit;
				--length;
		}
		return val;
}
				




int main(int argc, char **argv)
{
		std::vector<int> ivec;
		std::vector<int>::size_type size = static_cast<std::vector<int>::size_type>(str_to_int(argv[1]));
		std::vector<int>::size_type prev_size = ivec.size(), prev_capa = ivec.capacity();
		unsigned change_count = 0;
		while (ivec.size() < size)
		{
				ivec.push_back(0);
				if (ivec.capacity() != prev_capa)
				{
						std::cout << "capacity changed:\n" <<
								"previous capacity: " << prev_capa << "\n" <<
								"current capacity: " << ivec.capacity() << "\n" << 
								"prev_size: " << prev_size << "\n" <<
								"curr_size: " << ivec.size() << "\n" <<
								"change_count: " << ++change_count << "\n" << std::endl;
						prev_size = ivec.size();
						prev_capa = ivec.capacity();
				}
		}

		return 0;
}
