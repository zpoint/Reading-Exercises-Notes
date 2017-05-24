#include <iostream>
#include <sstream>
#include <string>

template <typename T> std::string debug_rep(const T &t)
{
		std::ostringstream ret;
		ret << t;
		std::cout << "Calling const T&t version: " << ret.str() << std::endl;
		return ret.str();
}

template <typename T> std::string debug_rep(T *p)
{
		std::cout << "Calling debug_rep T *p, p: " << p << " *p: " << *p  << " &p: " << &p << std::endl;
		std::ostringstream ret;
		ret << "pointer: " << p;
		if (p)
				ret << " " << debug_rep(*p);
		else
				ret << " null pointer";
		std::cout << "Calling const T *p version: " << ret.str() << std::endl;
		return ret.str();
}

std::string debug_rep(const std::string &s)
{
		std::cout << "Calling function const std::string &s " << ('"' + s + '"') << std::endl;
		return '"' + s + '"';
}

template <>
std::string debug_rep(char *p)
{
		std::cout << "Calling function char *p: " << p << std::endl;
		return debug_rep(std::string(p));
}

template <>
std::string debug_rep(const char *p)
{
		std::cout << "Calling function const char *p: " << p << std::endl;
		return debug_rep(std::string(p));
}

int main()
{
		char a[] = "aaaa";
		std::string b = "bbb";
		// debug_rep(a);
		debug_rep(&a);
		debug_rep(b);
		debug_rep(&b);
		return 0;
}
