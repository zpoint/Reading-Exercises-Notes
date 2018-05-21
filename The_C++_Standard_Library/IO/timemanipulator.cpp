#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>

int main()
{
		// process and print current date and time:
		std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
		time_t t = std::chrono::system_clock::to_time_t(now);
		std::tm* nowTM = std::localtime(&t);
		std::cout << std::put_time(nowTM, "date: %x\ntime: %X\n") << std::endl;

		// read date:
		std::tm date;
		std::cout << "new date: ";
		std::cin >> std::get_time(&date, "%x"); // read date
		if (!std::cin)
				std::cerr << "invalid format read" << std::endl;

		return 0;
}
