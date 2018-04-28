#include <unordered_map>
#include <string>
#include <iostream>

int main()
{
		std::unordered_map<std::string,double> coll 
		{
				{ "tim", 9.9 },
				{ "struppi", 11.77 }
		};
		
		// square the value of each element:
		for (std::pair<const std::string,double>& elem : coll)
				elem.second *= elem.second;

		// print each element (key and value):
		for (const auto &elem : coll)
				std::cout << elem.first << ": " << elem.second << std::endl;

		return 0;
}
