#include <iostream>

double absolute(double x)
{
	if (x < 0)
		return(-x);
	return(x);
}

int main()
{
	double x;
	std::cout << "Enter a number, I will generate it's absolute value:" << std::endl;
	while (!(std::cin >> x))
	{
		std::cout << "Invalid input, Try again" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cout << "Absolute value of " << x << " is " << absolute(x) << std::endl;
	return(0);
}