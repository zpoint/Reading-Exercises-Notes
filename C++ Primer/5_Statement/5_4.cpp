#include <iostream>
#include <string>

int main()
{
	std::string s = "string";
	std::string::iterator iter = s.begin();
	// a
	while (iter != s.end())
		++iter;
	// b
	// correct
	return(0);
}