#include <iostream>
#include <list>
#include <vector>
#include <string>

int main()
{
		std::list<const char *> lchars = {"abc", "cba", "def"}, rchars(10, "abc");
		std::vector<std::string> svec;
		svec.assign(lchars.cbegin(), lchars.cend());
		return 0;
}
