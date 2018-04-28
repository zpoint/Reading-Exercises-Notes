#include <array>
#include <string>
#include <iostream>

int main()
{
		// array container of 5 string elements
		std::array<std::string, 5> coll = {"hello", "world"};
		
		// print each element with its index on a line
		for (std::size_t i=0; i<coll.size(); ++i)
				std::cout << i << ": " << coll[i] << std::endl;
		return 0;
}
