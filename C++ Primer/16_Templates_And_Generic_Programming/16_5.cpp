#include <iostream>

template <typename T, unsigned N>
void print(const T (&arr)[N])
{
		for (const auto &item : arr)
				std::cout << item << " ";
		std::cout << std::endl;
}

void pr(int (&arr)[10])
{
		std::cout << arr << std::endl;
		*arr = 30;
}

int main()
{
		int arr[10] = {0,1,2,3,4};
		char iarr[5] = {'a', 'b'};
		pr(arr);
		print(arr);
		print(iarr);
		return 0;
}
