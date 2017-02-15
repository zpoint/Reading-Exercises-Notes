#include <iostream>
#include <string>

int main()
{
		std::string buffer = "President Trump said";
		std::string query = "trump";
		std::size_t pos = buffer.find_first_of(query);
		std::cout << pos << std::endl;
		return 0;
}

