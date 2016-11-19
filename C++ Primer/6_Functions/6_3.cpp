#include <iostream>

unsigned long long fact(unsigned long long x)
{
	if (x == 1)
		return (x);
	return (x * fact(x - 1));
}

unsigned long long fact_TailRec(unsigned long long x, unsigned long long result = 1)
{
	if (x == 1)
		return(result);
	return(fact_TailRec(x - 1, x * result));
}

int main()
{
	int x;
	unsigned long long x2;
	std::cout << "Input a number(> 0), I will compute the factorial" << std::endl;
	while (!(std::cin >> x) || x <= 0)
	{
		std::cout << "Ivalid input, Try again:" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	x2 = x;
	std::cout << "Factorial of " << x2 << " is " << fact_TailRec(x2) << std::endl;
	return(0);
}