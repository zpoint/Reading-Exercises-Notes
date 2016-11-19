#include <iostream>
#include <string>
#include <cstring>

int main()
{
		std::string str1, str2, tmp;
		std::cout << "Enter two string(std::string): " << std::endl;
		std::cin >> str1 >> str2;
		std::cout << "Enter two string(char arr[]):" << std::endl;
		std::cin >> tmp;
		char arr1[tmp.size() + 1];
		for (auto i = 0; i < tmp.size(); i++)
				arr1[i] = tmp[i];
		arr1[tmp.size() + 1] = '\0';
		std::cin >> tmp;
		char arr2[tmp.size() + 1];
		for (auto i = 0; i < tmp.size(); i++)
				arr2[i] = tmp[i];
		arr2[tmp.size() + 1] = '\0';

		// compare str1 and str2
		std::string result = "str1 < str2";
		if (str1 == str2)
				result = "str1 == str2";
		else if (str1 > str2)
				result = "str1 > str2";
		std::cout << result << std::endl;

		// compare two build-in arr
		int res = strcmp(arr1, arr2);
		if (res == 0)
				result = "arr1 == arr2";
		else if (res < 0)
				result = "arr1 < arr2";
		else
				result = "arr1 > arr2";
		std::cout << result << std::endl;
		return(0);
}
