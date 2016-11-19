#include <iostream>

int getvalue()
{
	int val;
	do
	{
		if (std::cin.fail())
		{
			std::cout << "Invalid Input, Please reenter an integer" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cin >> val;
	} while (!std::cin);
	return(val);
}

double div(double x, double y)
{
	if (y == 0.0)
		throw y;
	return(x / y);
}
int main()
{
	std::cout << "Input two integers, I will divide the first by two" << std::endl;
	int ival1 = getvalue(), ival2 = getvalue();
	double result;
recompute:
	try
	{
		result = div(static_cast<double>(ival1), static_cast<double>(ival2));
	}
	catch (double)
	{
		std::cout << "Divided by zero!! Please enter the second integer again!!!" << std::endl;
		ival2 = getvalue();
		goto recompute;
	}
	std::cout << result << std::endl;
	return(0);
}