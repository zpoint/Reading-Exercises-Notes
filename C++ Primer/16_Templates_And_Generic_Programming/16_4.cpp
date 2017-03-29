#include <list>
#include <string>
#include <iostream>

template <typename T_iter, typename T_val>
T_iter find(const T_iter &first_iterator, const T_iter &last_iterator, const T_val val)
{
		T_iter iterator = first_iterator;
		while (iterator != last_iterator)
		{
				if (*iterator == val)
						return iterator;
				++iterator;
		}
		return last_iterator;
}


int main()
{
		std::list<std::string> ls = {"123", "457", "aba", "cdc"};
		std::cout << *find(ls.begin(), ls.end(), "cdc") << std::endl;
		return 0;
}

