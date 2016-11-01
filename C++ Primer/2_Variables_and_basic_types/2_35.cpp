#include <iostream>

int main()
{
		const int i = 42;
		auto j = i; // int
		const auto &k = i; // const int&
		auto *p = &i; // pointer to const value
		return(0);
}
