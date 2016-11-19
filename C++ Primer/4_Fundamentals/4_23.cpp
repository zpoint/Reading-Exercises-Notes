#include <iostream>
#include <string>

int main()
{
		std::string s = "word";
		std::string p1 = s + (s[s.size() - 1] == 's' ? "" : "s");
		std::cout << p1 << std::endl;
		return(0);
}
