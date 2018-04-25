#include <memory>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <cerrno>
#include <string>
#include <iostream>

const char *FILE_PATH = "./tmp12345";

class SharedMemoryDetacher
{
		public:
			void operator() (int* p)
			{
					std::cout << "unlink " << FILE_PATH << std::endl;
					if (shm_unlink(FILE_PATH) != 0)
							std::cerr << "OOPS: shm_unlink() failed" << std::endl;
			}
};

std::shared_ptr<int> getSharedIntMemory(int num)
{
		void *mem;
		int shmfd = shm_open(FILE_PATH, O_CREAT|O_RDWR, S_IRWXU|S_IRWXG);
		if (shmfd < 0)
				throw std::string(strerror(errno));
		if (ftruncate(shmfd, num*sizeof(int)) == -1)
				throw std::string(strerror(errno));
		mem = mmap(nullptr, num*sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
		if (mem == MAP_FAILED)
				throw std::string(strerror(errno));
		std::cout << mem << std::endl;
		return std::shared_ptr<int>(static_cast<int*>(mem), SharedMemoryDetacher());
}

int main()
{
		std::shared_ptr<int> smp(getSharedIntMemory(100));
		for (int i = 0; i < 100; ++i)
				smp.get()[i] = i * 42;

		std::cout << (*smp) << std::endl; // I am an int
		std::cout << (&*smp) << std::endl; // I am a pointer to int
		std::cout << "<return>" << std::endl;
		std::cin.get();

		return 0;
}

