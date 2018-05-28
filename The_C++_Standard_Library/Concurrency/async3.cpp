#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>

void doSomething(char c)
{
		// random-number generator (use c as seed to get different sequences)
		std::default_random_engine dre(c);
		std::uniform_int_distribution<int> id (10, 1000);

		// loop to print character after a random period of time
		for (int i = 0; i < 10; ++i)
		{
				std::this_thread::sleep_for(std::chrono::milliseconds(id(dre)));
				std::cout.put(c).flush();
		}
}

int main()
{
		std::cout << "starting 2 operations asynchronously" << std::endl;

		// start two loops in the background printing characters . or +
		std::future<void> f1 = std::async([] { doSomething('.'); });
		std::future<void> f2 = std::async([] { doSomething('+'); });

		// if at least one of the background tasks in runnning
		if (f1.wait_for(std::chrono::seconds(0)) != std::future_status::deferred ||
			f2.wait_for(std::chrono::seconds(0)) != std::future_status::deferred)
		{
				// poll until at least oone of the loops finished
				while (f1.wait_for(std::chrono::seconds(0)) != std::future_status::ready &&
					   f2.wait_for(std::chrono::seconds(0)) != std::future_status::ready)
				{
						// std::cout << "no thread ready" << std::endl;
						std::this_thread::yield();
				}
		}
		std::cout.put('\n').flush();

		// wait for all loops to be finished and process any exception
		try
		{
				f1.get();
				f2.get();
		}
		catch (const std::exception& e)
		{
				std::cout << "\nEXCEPTION: " << e.what() << std::endl; 
		}
		std::cout << "\ndone" << std::endl;

		return 0;
}
