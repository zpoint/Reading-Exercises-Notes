#include "algostuff.hpp"


int main()
{
		// initialize source collection with ''..........abcdef..........''
		std::vector<char> source(10, '.');
		for (int c = 'a'; c <= 'f'; ++c)
				source.push_back(c);

		source.insert(source.end(), 10, '.');
		PRINT_ELEMENTS(source, "source:  ");

		// copy all letters three elements in front of the 'a'
		std::vector<char> c1(source.cbegin(), source.cend());
		std::copy(c1.cbegin() + 10, c1.cbegin() + 16, c1.begin() + 7);
		PRINT_ELEMENTS(c1, "c1:      ");

		// copy all letters three elements behind the 'f'
		std::vector<char> c2(source.cbegin(), source.cend());
		std::copy_backward(c2.cbegin() + 10, c2.cbegin() + 16, c2.begin() + 19);	
		PRINT_ELEMENTS(c2, "c2:      ");	

		return 0;
}
