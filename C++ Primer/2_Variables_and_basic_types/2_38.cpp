#include <iostream>

int main()
{
		int a = 0;
		const int b = 1;
		auto c = a; // same 
		decltype(a) d = a; // same

		auto e = b; // differ
		decltype(b) f = b; // differ
		e = 3;
		return(0);
}
