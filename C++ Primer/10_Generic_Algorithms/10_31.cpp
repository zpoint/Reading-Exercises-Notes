#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main()
{
		std::istream_iterator<int> istream_int(std::cin), eof;
		std::ostream_iterator<int> ostream_int(std::cout, " ");
		std::vector<int> ivec;
		while (istream_int != eof)
				ivec.push_back(*istream_int++);
		std::sort(ivec.begin(), ivec.end());
		std::unique_copy(ivec.begin(), ivec.end(), ostream_int);
		std::cout << std::endl;
		return 0;
}
