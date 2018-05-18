#include "icstring.hpp"

int main()
{
		icstring s1("hallo");
		icstring s2("otto");
		icstring s3("hALLo");

		std::cout << std::boolalpha;
		std::cout << s1 << " == " << s2 << " : " << (s1 == s2) << std::endl;
		std::cout << s1 << " == " << s3 << " : " << (s1 == s3) << std::endl;

		icstring::size_type idx = s1.find("All");
		if (idx != icstring::npos)
		{
				std::cout << "index of \"All\" in \"" << s1 << "\": " << idx << std::endl;
		}
		else
				std::cout << "\"All\" not found in \"" << s1 << "\"" << std::endl;

		return 0;
}
