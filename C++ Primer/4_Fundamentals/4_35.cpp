#include <iostream>

int main()
{
		char cval;
		int ival;
		unsigned int ui;
		float fval;
		double dval;

		cval = 'a' + 3; // 'a' convert to int, after +, convert back to char
		std::cout << "cval: " << cval << std::endl;
		fval = ui - ival * 1.0; // ival to double, ui to double, result to float
		std::cout << "fval: " << fval << std::endl;
		dval = ui * fval; // unsigned int to float, after *, result to double
		std::cout << "dval: " << dval << std::endl;
		cval = ival + fval + dval; // int to float, result to double, final result to char
		std::cout << "cval: " << cval << std::endl;
		return(0);
}
