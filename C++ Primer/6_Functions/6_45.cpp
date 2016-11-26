#include <iostream>
#include <string>
using std::string;

inline  constexpr bool isShorter(const string &s1, const string &s2)
{
		return true;
}

int main()
{
		const string s1 = "dffdf";
		const string s2 = "cccccc";
		std::cout << isShorter(s1, s2) << std::endl;
		return 0;
}
