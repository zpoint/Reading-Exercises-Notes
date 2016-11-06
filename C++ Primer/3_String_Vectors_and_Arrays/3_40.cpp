#include <iostream>
#include <cstring>

int main()
{
		char arr1[] = "I am arr1";
		char arr2[] = "I am arr2";
		char arr3[strlen(arr1) + strlen(arr2) + 1];
		strcpy(arr3, arr1);
		strcat(arr3, arr2);
		std::cout << arr3 << std::endl;
		return(0);
}
