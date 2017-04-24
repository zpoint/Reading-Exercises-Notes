#include <iostream>
#include <vector>

template <typename T> void g(T&& val)
{
		std::vector<T> v;
		v.push_back(val);
}

int main()
{
		int i = 2;
		g(42); // rval, vector of int
		// g(i); // vector of int& error
		// std::vector<int&> v;  error
		return 0;
}
