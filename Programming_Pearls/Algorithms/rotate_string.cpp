#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

std::size_t gcd(std::size_t a, std::size_t b)
{
		std::size_t r = a % b;
		if (r)
				return gcd(b, r);
		else
				return b;
}

struct Rotate
{
		public:
				std::string rotate(std::size_t rotate_size, std::string str_to_rotate, std::string method="juggling");
		private:
			std::string juggling(std::size_t rotate_size, std::string &str);
			std::string flip(std::size_t roate_size, std::string &str);
};

std::string Rotate::rotate(std::size_t rotate_size, std::string str_to_rotate, std::string method)
{
		if (method == "juggling")
				return juggling(rotate_size, str_to_rotate);
		else
				return flip(rotate_size, str_to_rotate);
}

std::string Rotate::juggling(std::size_t rotate_size, std::string &str)
{
		// copy to c str
		char *c_str = (char *)malloc(sizeof(char) * (str.size() + 1));
		for (std::size_t i = 0; i < str.size(); ++i)
			c_str[i] = str[i];
		c_str[str.size()] = '\0';
		
		if (rotate_size > str.size())
				rotate_size = str.size() % rotate_size;
		std::size_t loop_time = gcd(str.size(), rotate_size);
		for (std::size_t initial_i = 0; initial_i < loop_time; ++initial_i)
		{
				char temp = c_str[initial_i];
				std::size_t j = initial_i, i = initial_i;
				// forward j
				j += rotate_size;
				if (j >= str.size())
						j -= str.size();
				while (j != initial_i)
				{
						// rotate
						c_str[i] = c_str[j];
						// forward i
						i = j;
						// forward j
						j += rotate_size;
						if (j >= str.size())
								j -= str.size();
				}
				// done
				c_str[i] = temp;
		}
		std::string ret_str = std::string(c_str);
		free(c_str);
		return ret_str;

}

void flip_str(char *c_arr, std::size_t start_index, std::size_t stop_index)
{
		char temp;
		while (start_index < stop_index)
		{
				temp = c_arr[start_index];
				c_arr[start_index] = c_arr[stop_index];
				c_arr[stop_index] = temp;
				++start_index;
				--stop_index;
		}
}

std::string Rotate::flip(std::size_t rotate_size, std::string &str)
{
		if (rotate_size > str.size())
				rotate_size = str.size() % rotate_size;
		if (rotate_size == str.size())
				return str;
		// copy c_str
		char *c_str = (char *)malloc(sizeof(char) * (str.size() + 1));
		for (std::size_t i = 0; i < str.size(); ++i)
				c_str[i] = str[i];
		c_str[str.size()] = '\0';

		std::size_t mid_index = rotate_size - 1;
		flip_str(c_str, 0, mid_index);
		flip_str(c_str, mid_index + 1, str.size() - 1);
		flip_str(c_str, 0, str.size() - 1);
		std::string ret_str = std::string(c_str);
		free(c_str);
		return ret_str;
}


void performance_test(std::string str)
{
		unsigned int test_time = 1 << 20;
		Rotate r = Rotate();
		std::vector<std::string> methods = {"juggling", "flip"};
		for (std::size_t sz = 1; sz < str.size(); ++sz)
		{
				std::cout << "\nrotate size: " << sz << " juggling result: " << r.rotate(sz, str) << " flip result: " << r.rotate(sz, str, "flip") << std::endl;
				for (auto &method: methods)
				{
						auto start = std::chrono::high_resolution_clock::now();
						for (unsigned count = 0; count < test_time; ++count)
								r.rotate(sz, str, method);
						auto elapsed = std::chrono::high_resolution_clock::now() - start;
						long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
						std::cout << "method: " << method << ", rotate_size: " << sz << ", perform:" << test_time << " times, cost: " << microseconds / 1000.0 << " milliseconds" << std::endl;
				}
		}
}

int main()
{
		Rotate r = Rotate();
		/*
		std::string str;
		std::size_t size;
		std::cout << "Enter a string, and a rotate size, I will perform rotate test" << std::endl;
		while (std::cin >> str >> size)
		{
				std::cout << r.rotate(size, str, "flip") << std::endl;
		}
		*/
		performance_test("goooooooooooooooood");
		return 0;
}
