#include <iostream>
#include <string>
#include <cctype>

int main()
{
	std::string buf;
	std::cout << "Enter soem strings, I will report duplicated strings start with uppercase letter" << std::endl;
	while (std::cin >> buf && !buf.empty())
	{
		if (!std::isupper(buf[0]))
			continue;
		std::cout << buf << std::endl;
	}
	return(0);
}