#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

std::string asString (const std::chrono::system_clock::time_point &tp)
{
		std::time_t t = std::chrono::system_clock::to_time_t(tp); // convert to system time
		std::string ts = std::ctime(&t); // convert to calendar time
		ts.resize(ts.size()-1);
		return ts;
}

int main()
{
		// define type for durations tha represent day(s):
		typedef std::chrono::duration<int, std::ratio<3600*24>> Days;

		// process the epoch of this system clock
		std::chrono::time_point<std::chrono::system_clock> tp;
		std::cout << "epoch:       " << asString(tp) << std::endl;

		// add one day, 23 hours, and 55 minutes
		tp += Days(1) + std::chrono::hours(23) + std::chrono::minutes(55);
		std::cout << "later:       " << asString(tp) << std::endl;

		// process difference from epoch in minutes and days
		std::chrono::system_clock::duration diff = tp - std::chrono::system_clock::time_point();
		std::cout << "diff:        " << std::chrono::duration_cast<std::chrono::minutes>(diff).count() << " minutes(s)" << std::endl;
		Days days = std::chrono::duration_cast<Days>(diff);
	    std::cout << "diff:        " << days.count() << " day(s)" << std::endl;

		// substract one year(hoping it is valid and not a leap year)
		tp -= std::chrono::hours(24*365);
		std::cout << "-1 year  :   " << asString(tp) << std::endl;

		// substract 50 years (hoping it is valid and ignore leap year)
		tp -= std::chrono::duration<int, std::ratio<3600*24*365>>(50);
		std::cout << "-50 y  ears: " << asString(tp) << std::endl;

		// substract 50 years (hoping it is valid and ognoring lead years)
		tp -= std::chrono::duration<int, std::ratio<3600*24*365>>(1000000);
		std::cout << "-100W years:  " << asString(tp) << std::endl;
		return 0;
}
