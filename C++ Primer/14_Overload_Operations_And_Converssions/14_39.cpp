#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class test {
		public:
				test(std::size_t up_bd, std::size_t low_bd, std::size_t upp): upper_bound(up_bd), lower_bound(low_bd), upuper_bound(upp) { }
				bool operator()(const std::string &str1) const
				{
						return (str1.size() <= upper_bound && str1.size() >= lower_bound) || (str1.size() > upuper_bound);
				}
		private:
				std::size_t upper_bound;
				std::size_t lower_bound;
				std::size_t upuper_bound;
};

int main(int argc, char **argv)
{
		if (argc != 2)
				throw std::runtime_error("Usage: program filename");
		std::ifstream in(argv[1]);
		if (!in)
				throw std::runtime_error("Unable to open file: " + std::string(argv[1]));

		test t(9, 1, 10);
		std::size_t count = 0;
		std::string buffer;
		while (in >> buffer)
		{
				if (t(buffer))
				{
						std::cout << buffer << " in range\r\n";
						++count;
				}
				else
						std::cout << buffer << " not in range\r\n";
		}
		std::cout << count << " words in range" << std::endl;
		return 0;
}
