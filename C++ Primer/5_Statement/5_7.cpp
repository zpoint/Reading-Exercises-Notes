#include <iostream>

int get_value()
{
	int val;
	std::cout << "In function get_value, Please enter an integer:" << std::endl;
	while (1)
	{
		std::cin >> val;
		if (std::cin.fail())
		{
			std::cout << "Invalid input, Please enter an integer!!!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			return(val);
	}
}

int main()
{
	int ival1 = 1, ival2 = 0;
	// a
	if (ival1 != ival2)
		ival1 = ival2;
	else
		ival1 = ival2 = 0;

	int ival = 2, minval = 1, occurs = 0;
	// b
	if (ival < minval)
	{
		minval = ival;
		occurs = 1;
	}

	// c
	int iival;
	if (iival = get_value())
		std::cout << "ival = " << ival << std::endl;
	if (!iival)
		std::cout << "ival = 0\n";

	// d
	if (iival == 0)
		iival = get_value();
	return(0);
}