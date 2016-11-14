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

int main()
{
	std::cout << "Input two integers, I will divide the first by two" << std::endl;
	int ival1 = getvalue(), ival2 = getvalue();
	std::cout << static_cast<double>(ival1) / static_cast<double>(ival2) << std::endl;
	return(0);
}