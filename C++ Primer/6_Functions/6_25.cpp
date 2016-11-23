#include <iostream>
#include <string>

int main(int argc, char **argv)
{
		std::string str;
		char *c;
		while ((c = *argv++) != nullptr)
				str += c;
		std::cout << str << std::endl;
		return 0;
}

