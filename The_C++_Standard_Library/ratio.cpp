#include <ratio>
#include <limits>
#include <iostream>

int main()
{
		typedef std::ratio<5, 3> FiveThirds;
		std::cout << FiveThirds::num << "/" << FiveThirds::den << std::endl;

		typedef std::ratio<25, 15> AlsoFiveThirds;
		std::cout << AlsoFiveThirds::num << "/" << AlsoFiveThirds::den << std::endl;

		std::ratio<42, 42> one;
		std::cout << one.num << "/" << one.den << std::endl;

		std::ratio<0> zero;
		std::cout << zero.num << "/" << zero.den << std::endl;

		typedef std::ratio<7, -3> Neg;
		std::cout << Neg::num << "/" << Neg::den << std::endl;

		std::ratio_multiply<std::ratio<1, std::numeric_limits<int>::max()>, std::ratio<1, 2>>::type t; // change int to long long, compile error
		// std::ratio_divide<FiveThirds, std::ratio<0>> d;
		return 0;
}
