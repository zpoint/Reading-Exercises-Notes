#include <iostream>
#include <iomanip>
#include <chrono>

template <typename V, typename R>
std::ostream& operator << (std::ostream& s, const std::chrono::duration<V, R>& d)
{
		s << "[" << d.count() << " of " << R::num << "/" << R::den << "]";
		return s;
}

int main()
{
		std::chrono::seconds twentySeconds(20); // 20 seconds
		std::chrono::hours aDay(24); // 24 hour

		std::chrono::milliseconds ms1(0); // 0 milliseconds (undefined value without initial value!)
		ms1 += twentySeconds + aDay; // 86420000 milliseconds
		--ms1; // 86419999 millseconds
		ms1 *= 2; // 172839998 milliseconds
		std::cout << ms1.count() << " ms1" << std::endl;
		std::cout << std::chrono::nanoseconds(ms1).count() << " ns" << std::endl;
		std::cout << twentySeconds << "\n"
				  << aDay << "\n"
				  << ms1 << "\n" << std::endl;

		std::chrono::seconds sec(55);
		// std::chrono::minutes m1(sec); // Error
		std::chrono::minutes m2 = std::chrono::duration_cast<std::chrono::minutes>(sec); // OK
		std::cout << sec << "\n" << m2 << "\n" << std::endl;

		std::chrono::duration<double, std::ratio<60>> halfMin(0.5);
		// std::chrono::seconds s1 = halfMin; // Error
		std::chrono::seconds s2 = std::chrono::duration_cast<std::chrono::seconds>(halfMin); // OK
		std::cout << halfMin << "\n" << s2 << "\n" << std::endl;

		std::chrono::milliseconds ms(7255042);
		std::chrono::hours hh = std::chrono::duration_cast<std::chrono::hours>(ms);
		std::chrono::minutes mm = std::chrono::duration_cast<std::chrono::minutes>(ms % std::chrono::hours(1));
		std::chrono::seconds ss = std::chrono::duration_cast<std::chrono::seconds>(ms % std::chrono::minutes(1));
		std::chrono::milliseconds msec = std::chrono::duration_cast<std::chrono::milliseconds>(ms % std::chrono::seconds(1));

		std::cout << "raw: " << hh << "::" << mm << "::"
				             << ss << "::" << msec << std::endl;
		std::cout << "     " << std::setfill('0') << std::setw(2) << hh.count() << "::"
				                                  << std::setw(2) << mm.count() << "::"
												  << std::setw(2) << ss.count() << "::"
												  << std::setw(3) << msec.count() << std::endl;
		return 0;
}
