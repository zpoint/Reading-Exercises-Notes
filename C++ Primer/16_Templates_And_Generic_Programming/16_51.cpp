#include <iostream>
#include <string>

template <typename ... Args> void g(Args ... args)
{
		std::cout << "sizeof(Args): " << sizeof...(Args) << std::endl;
		std::cout << "sizeof(args): " << sizeof...(args) << std::endl;
}

int main()
{
		int i = 0; 
		double d = 3.14;
		std::string s = "how now brown cow", ss = "sdas";
		g("hi");
		g(d, s);
		g(s, 42, "hi");
		g(i, s, 42, d);
		g(42, s, ss, ss);
		return 0;
}
