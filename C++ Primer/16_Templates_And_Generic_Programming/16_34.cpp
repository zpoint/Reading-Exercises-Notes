#include <string>
#include <iostream>

template <class T> int compare(const T&, const T&)
{
		std::cout << "Calling compare" << std::endl;
		return 0;
}
		

int main()
{
		// a
		compare("hiwww", "world");  // illegal, char[3] != char[6]
		// b
		compare("bye", "dad");
		return 0;
}
