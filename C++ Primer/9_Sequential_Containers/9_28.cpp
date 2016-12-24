#include <forward_list>
#include <string>
#include <iostream>

void find_and_insert(std::forward_list<std::string> &flst, const std::string str1, const std::string str2)
{
		std::forward_list<std::string>::iterator curr = flst.begin(), prev = flst.before_begin();
		while (curr != flst.end())
		{
				if (*curr == str1)
				{
						curr = flst.insert_after(curr, str2);
						break;
				}
				++prev;
				++curr;
		}
		if (curr == flst.end())
				flst.insert_after(prev, str2);
}

int main()
{
		std::forward_list<std::string> flst = {"123", "456", "asd", "cds", "wewe"};
		std::cout << "Before calling find_and_insert: " << std::endl;
		for (const auto i : flst)
				std::cout << i << " ";
		std::cout << std::endl;
		find_and_insert(flst, "asd", "str_to_insert");
		std::cout << "After calling find_and_insert('asd', 'str_to_insert'): " << std::endl;
		for (const auto i : flst)
				std::cout << i << " ";
		std::cout << std::endl;
		find_and_insert(flst, "nono", "yeah");
		std::cout << "After calling find_and_insert('nono', 'yeah'): " << std::endl;
		for (const auto i : flst)
				std::cout << i << " ";
		std::cout << std::endl;
		return 0;
}
