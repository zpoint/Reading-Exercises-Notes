#include <iostream>
#include <fstream>

void hexMultiplicationTable(std::streambuf* buffer, int num)
{
		std::ostream hexout(buffer);
		hexout << std::hex << std::showbase;

		for (int i = 1; i <= num; ++i)
		{
				for (int j = 1; j <= 10; ++j)
						hexout << i * j << ' ';
				hexout << std::endl;
		}
} // does not close buffer

int main()
{
		int num = 5;

		std::cout << "We print " << num << "lines hexadecimal" << std::endl;

		hexMultiplicationTable(std::cout.rdbuf(), num);

		std::cout << "That was the output of " << num << " hexadecimal lines " << std::endl;
		return 0;
}
