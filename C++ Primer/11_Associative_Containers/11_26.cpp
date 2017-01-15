/*
 * Key type can be uses to subscript a map
 * mapped_type does the subscript operator return
 */

#include <map>
#include <string>

int main()
{
		std::map<int, std::string> imap;
		int key = 1;
		std::string str = "aaa";
		imap[key] = str;
		std::string str2 = imap[key];
		return 0;
}
