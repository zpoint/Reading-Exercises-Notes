#include <iostream>
#include <string>

template <typename T, typename ... Args>
std::ostream &print(std::ostream &os, const T &t, const Args& ... rest)
{
		os << t << ", ";
		return print(os, rest...);  // call itself until no match function
}

template <typename T>
std::ostream &print(std::ostream &os, const T &t)
{
		return os << t;
}

int main()
{
		int i = 0;
		double d = 3.14;
		std::string s = "how now brown cow";
		print(std::cout, i, d, s);
		print(std::cout, i, d, s, i);
		return 0;
}
