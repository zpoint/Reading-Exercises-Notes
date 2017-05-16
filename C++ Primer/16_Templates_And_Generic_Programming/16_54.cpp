#include <iostream>
#include <string>

template <typename T>
std::ostream &print(std::ostream &os, const T &t)
{
		return os << t;
}

template <typename T, typename ... Args>
std::ostream &print(std::ostream &os, const T &t, const Args& ... rest)
{
		os << t << ", ";
		return print(os, rest...);
}

struct no_cout {
};

int main()
{
		int i = 0;
		double d = 3.14;
		std::string s = "how now brown cow";
		no_cout n;
		print(std::cout, i, d, s);
		print(std::cout, i, d, s, i, n); // won't compile
		return 0;
}
