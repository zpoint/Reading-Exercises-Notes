#include <iostream>
#include <string>

struct Data {
		int ival;
		std::string s;
		// constexpr Data(int i, std::string s1): ival(i), s(s1) { }
};

int main()
{
		/*
		 * No, string is not a literal type
		 */
		Data d{3, "sss"};
		return 0;
}
