#include <iostream>
#include <string>
#include <memory>

int main()
{
		std::size_t n;
		std::allocator<std::string> str_alloc;
		std::string s;

		std::cout << "Enter number of size (> 0)" << std::endl;
		std::cin >> n;
		std::string *const p = str_alloc.allocate(n);
		std::string *q = p;
		std::cout << "Now enter " << n << " strings" << std::endl;
		// construct
		for (std::size_t index = 0; index < n; ++index)
		{
				std::cin >> s;
				str_alloc.construct(q++, s);
		}
		// print
		q = p;
		for (std::size_t index = 0; index < n; ++index)
				std::cout << *(q++) << std::endl;
		// destory
		while (q != p)
				str_alloc.destroy(--q);
		// deallocate
		str_alloc.deallocate(p, n);

		return 0;
}
