#include <chrono>
#include <thread>
#include "clock.hpp"

int main()
{
		std::cout << "system_clock: " << std::endl;
		printClockData<std::chrono::system_clock>();
		std::cout << "\nhigh_resoultion_clock: " << std::endl;
		printClockData<std::chrono::high_resolution_clock>();
		std::cout << "\nsteady_clock: " << std::endl;
		printClockData<std::chrono::steady_clock>();

		std::chrono::system_clock::time_point system_start = std::chrono::system_clock::now();
		std::this_thread::sleep_for(std::chrono::seconds(2));
		if (std::chrono::system_clock::now() > system_start + std::chrono::seconds(1))
		{
				// may fail, system clock may be adjusted
				std::cout << "Here" << std::endl;
		}
		else
				std::cout << "Not Here" << std::endl;

		std::chrono::system_clock::duration diff = std::chrono::system_clock::now() - system_start;
		std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
		std::cout << "this program runs: " << sec.count() << " seconds" << std::endl;
		return 0;
}
