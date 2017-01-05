#include <fstream>
#include <iterator>
#include <cassert>

int main(int argc, char **argv)
{
		assert (argc == 4);
		std::ifstream fin(argv[1]);
		std::ofstream fodd(argv[2]), feven(argv[3]);
		assert (fin.good() and fodd.good() and feven.good());
		std::istream_iterator<int> is_iter(fin), eof;
		std::ostream_iterator<int> os_odd(fodd, " "), os_even(feven, "\n");
		while (is_iter != eof)
		{
				int tmp = *is_iter++;
				if (tmp % 2) // odd
						os_odd = tmp;
				else
						os_even = tmp;
		}
		return 0;
}
