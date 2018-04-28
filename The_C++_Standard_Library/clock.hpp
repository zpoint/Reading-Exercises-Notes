#include <chrono>
#include <iostream>
#include <iomanip>

template <typename C>
void printClockData ()
{
		std::cout << "- precision: ";
		// if time unit is less or equal one millsecond
		typedef typename C::period P; // type of time unit
		if (std::ratio_less_equal<P, std::milli>::value)
		{
				// convert to and print as millseconds
				typedef typename std::ratio_multiply<P, std::kilo>::type TT;
				std::cout << std::fixed << double(TT::num) / TT::den << " milliseconds" << std::endl;
		}
		else
		{
				// print as seconds
				std::cout << std::fixed << double(P::num) / P::den << " seconds" << std::endl;
		}
		std::cout << "- is_steady: " << std::boolalpha << C::is_steady << std::endl;
}
