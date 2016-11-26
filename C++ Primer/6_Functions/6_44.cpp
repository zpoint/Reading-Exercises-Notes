#include <iostream>
#include <string>
using std::string;

inline bool isShorter(const string &s1, const string &s2)
{
		return s1.size() > s2.size();
}

int main()
{
		const string s1 = "dffdf";
		const string s2 = "cccccc";
		std::cout << isShorter(s1, s2) << std::endl;
		return 0;
}
