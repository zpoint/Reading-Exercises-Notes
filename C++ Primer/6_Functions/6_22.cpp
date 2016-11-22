#include <iostream>

void swapTwoInt(int *ptr1, int *ptr2)
{
		int tmp = *ptr2;
		*ptr2 = *ptr1;
		*ptr1 = tmp;
}

void swapByReference(int &a, int &b)
{
		int tmp = b;
		b = a;
		a = tmp;
}

int main()
{
		int a = 10, b = 20;
		std::cout << "Before swap, a: " << a << " b: " << b << std::endl;
		swapByReference(a, b);
		std::cout << "After swap, a: " << a << " b: " << b << std::endl;
		return 0;
}
