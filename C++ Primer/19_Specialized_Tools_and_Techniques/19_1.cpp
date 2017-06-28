#include <cstdlib>
#include <iostream>

void *operator new(size_t size)
{
		std::cout << "In my function operator new" << std::endl;
		std::cout << "Size: " << size << std::endl;
		if (void *mem = malloc(size))
				return mem;
		else
				throw std::bad_alloc();
}

void operator delete(void *mem) noexcept
{
		std::cout << "In my function operator delete" << std::endl;
		free(mem);
}

int main()
{
		int *i = new int(5);
		int *j = new int [4];
		return 0;
}
