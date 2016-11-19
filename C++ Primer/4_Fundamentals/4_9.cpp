#include <iostream>

int main()
{
		const char *cp = "Hello World";
		if (cp != nullptr && *cp != '\0')
				std::cout << "True" << std::endl;
		return(0);
}
