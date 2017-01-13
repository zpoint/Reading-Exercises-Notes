#include <map>
#include <iostream>
#include <vector>

int main()
{
		std::map<int, std::vector<int>> ivec_map;
		std::map<int, std::vector<int>>::mapped_type i = {1, 2, 3}; // vector<int>
		std::map<int, std::vector<int>>::key_type j = 3; // int
		std::map<int, std::vector<int>>::value_type v_pair(1, {1,2,3}); // pair <const int, vector<int>>
		std::cout << v_pair.first << " " << std::endl;
		return 0;
}
