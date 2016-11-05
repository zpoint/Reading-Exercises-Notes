#include <iostream>
int txt_size();

		unsigned buf_size = 1024;
		// int ia[buf_size]; // illegal, buf_size not const
		int iab[4*7 - 14]; // ok
		//int iac[txt_size()]; // variable length not allowed 
int txt_size()
{
		return(1);
}
int main()
{
		// char st[11] = "fundamental"; illegal, array too long
		return(0);
}
