#include <iostream>
#include <vector>


int main()
{
		int arr1[] = {1,2,3,4,5,6,7,8,9,10};
		int arr2[] = {1,2,3,4,5,6,7,8,9,11};
		bool equal_arr = true;
		if (sizeof(arr1) != sizeof(arr2))
				equal_arr = false;
		else
				for (auto i = 0; i < 10; i++)
						if (arr1[i] != arr2[i])
						{
								equal_arr = false;
								break;
						}

		std::vector<int> vec1(10, 0), vec2(10, 0);
		vec2[9] = 9;
		bool euql_vec = true;
		if (vec1 != vec2)
				euql_vec = false;

		std::cout << "arr1 == arr2: " << (equal_arr ? "True" : "False") << " vec1 == vec2: " << (euql_vec ? "True" : "False") << std::endl;

		return(0);
}
