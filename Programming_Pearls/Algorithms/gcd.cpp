#include <iostream>

int gcd(int a, int b)
{
		int r = a % b;
		if (!r)
				return b;
		else
				return gcd(b, r);
}


int main()
{
		int a, b;
		std::cout << "Enter two number, I will calculate gcd of them" << std::endl;
		while (std::cin >> a >> b)
		{
				std::cout << "gcd of " << a << " and " << b << " is " << gcd(a, b) << "\n";
		}
}
