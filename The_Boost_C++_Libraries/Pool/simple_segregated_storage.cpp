#include <boost/pool/simple_segregated_storage.hpp>
#include <vector>
#include <cstddef>
#include <iostream>

int main()
{
		boost::simple_segregated_storage<std::size_t> storage;
		std::vector<char> v(1024);
		storage.add_block(&v.front(), v.size(), 256);

		int *i = static_cast<int*>(storage.malloc());
		*i = 1;

		int *j = static_cast<int*>(storage.malloc_n(1, 512));
		j[10] = 2;

		std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
		storage.free(i);
		storage.free_n(j, 1, 512);
		return 0;
}
