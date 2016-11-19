#include <iostream>

int main()
{
	// a
	do // need block {} 
	{
		int v1, v2;
		std::cout << "Please enter two numbers to sum: ";
		if (std::cin >> v1 >> v2)
			std::cout << "Sum is: " << v1 + v2 << std::endl;
	} while (std::cin);

	// b
	int ival = 0;
	do
	{
		// ival should be declared before do
	} while (ival);

	// c, same
	// int ival
	do
	{
		ival = 0;
	} while (ival);

	return(0);
}