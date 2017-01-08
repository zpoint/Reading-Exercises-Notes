#include <list>
#include <iostream>
#include <string>
#include <iterator>

int main()
{
		std::list<std::string> lst_words;
		std::istream_iterator<std::string> is_iter(std::cin), eof;
		while (is_iter != eof)
				lst_words.push_back(*is_iter++);
		lst_words.sort();
		lst_words.unique();
		for (const auto &i : lst_words)
				std::cout << i << " ";
		std::cout << std::endl;
		return 0;
}
