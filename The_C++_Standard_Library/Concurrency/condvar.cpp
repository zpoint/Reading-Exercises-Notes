#include <condition_variable>
#include <mutex>
#include <future>
#include <iostream>

bool readyFlag;
std::mutex readyMutex;
std::condition_variable readyCondVar;

void thred1()
{
		// do something thread2 needs as preparation
		std::cout << "<return>" << std::endl;
		std::cin.get();

		// signal that thread1 has prepared a condition
		{

				std::lock_guard<std::mutex> lg(readyMutex);
				std::cout << "gain mutex in thread1" << std::endl;
				readyFlag = true;
		} // release lock
		readyCondVar.notify_one();
}

void threa2()
{
		// wait until thread1 is ready(readyFlag is true)
		{
				std::unique_lock<std::mutex> ul(readyMutex);
				std::cout << "gain mutex in thread2" << std::endl;
				readyCondVar.wait(ul, []{ return readyFlag; });
		} // release lock
		// do whatever shall happen after thread1 has prepared things
		std::cout << "done" << std::endl;
}

int main()
{
		std::future<void> f1 = std::async(std::launch::async, thred1);
		std::future<void> f2 = std::async(std::launch::async, threa2);
		return 0;
}
