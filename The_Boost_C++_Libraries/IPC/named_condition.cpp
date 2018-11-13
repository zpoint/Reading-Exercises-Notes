#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <boost/interprocess/sync/named_condition.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <iostream>
#include <chrono>
#include <random>

using namespace boost::interprocess;

void sleep_random_seconds()
{
		std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
		std::uniform_int_distribution<int> distribution(1, 5);
		int dice_roll = distribution(generator);
		std::cout << "goint to sleep " << dice_roll << " seconds" << std::endl;
		sleep(dice_roll);
		std::cout << "sleep done" << std::endl; 
} 

int main()
{
		// sleep_random_seconds();
		
		// shared_memory_object::remove("shm");
		// named_mutex::remove("mtx");
		// named_condition::remove("cnd");
		// return 0;

		managed_shared_memory managed_shm{open_or_create, "shm", 1024};
		int *i = managed_shm.find_or_construct<int>("Integer")(0);
		named_mutex named_mtx{open_or_create, "mtx"};
		named_condition named_cnd{open_or_create, "cnd"};
		scoped_lock<named_mutex> lock{named_mtx};
		std::cout << "after lock" << std::endl;
		while (*i < 10)
		{
				if (*i % 2 == 0)
				{
						++(*i);
						named_cnd.notify_all();
						named_cnd.wait(lock);
				}
				else
				{
						std::cout << *i << std::endl;
						++(*i);
						named_cnd.notify_all();
						named_cnd.wait(lock);
				}
		}
		named_cnd.notify_all();
		shared_memory_object::remove("shm");
		named_mutex::remove("mtx");
		named_condition::remove("cnd");
		return 0;
}
