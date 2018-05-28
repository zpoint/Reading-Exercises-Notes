#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>

void doSomething(int num, char c)
{
		try
		{
				// random-number generator(use c as seed to get different sequences)
				std::default_random_engine dre(42 * c);
				std::uniform_int_distribution<int> id(10, 1000);
				for (int i = 0; i < num; ++i)
				{
						std::this_thread::sleep_for(std::chrono::milliseconds(id(dre)));
						std::cout.put(c).flush();
				}
		}
		// make sure no exception leaves the thread and terminates the program
		catch (const std::exception& e)
		{
				std::cerr << "THREAD-EXCEPTION (thread " << std::this_thread::get_id() << "): " << e.what() << std::endl;	
		}
		catch (...)
		{
				std::cerr << "THREAD-EXCEPTION (thread " << std::this_thread::get_id() << ")" << std::endl;
		}
}

int main()
{
		try
		{
				std::thread t1(doSomething, 5, '.'); // print five dots in seperate thread
				std::cout << "- started fg thread " << t1.get_id() << std::endl;

				// print other characters in other background thread
				for (int i = 0; i < 5; ++i)
				{
						std::thread t(doSomething, 10, 'a' + i); // print 10 chars in seperate thread
						std::cout << "- detach started bg thread " << t.get_id() << std::endl;
						t.detach(); // detach thread into the background
				}

				std::cin.get(); // wait for any input(return)
				std::cout << "- join fg thread " << t1.get_id() << std::endl;
				t1.join(); // wait for t1 to finish
		}
		catch (const std::exception& e)
		{
				std::cerr << "EXCEPTION: " << e.what() << std::endl;
		}

		return 0;
}
