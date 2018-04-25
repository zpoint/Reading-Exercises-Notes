#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main()
{
		// use textual representation for bool
		std::cout << std::boolalpha;

		// print maximun of integral types
		std::cout << "max(short): " << std::numeric_limits<short>::max() << std::endl;
		std::cout << "max(int): " << std::numeric_limits<int>::max() << std::endl;
		std::cout << "max(long): " << std::numeric_limits<long>::max() << std::endl;
		std::cout << std::endl;

		// print maximum of floating-point types
		std::cout << "max(float):       " << std::numeric_limits<float>::max() << std::endl;
		std::cout << "max(double):      " << std::numeric_limits<double>::max() << std::endl;
		std::cout << "max(long double): " << std::numeric_limits<long double>::max() << std::endl;
		std::cout << std::endl;

		// print whether char is signed
		std::cout << "is_signed(char): " << std::numeric_limits<char>::is_signed << std::endl;
		std::cout << std::endl;

		// print whether numeric limits for type string exist
		std::cout << "is_specialized(string): " << std::numeric_limits<std::string>::is_specialized << std::endl;
		return 0;	
}
