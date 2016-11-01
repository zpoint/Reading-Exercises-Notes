#include <iostream>

int main()
{
		// a
		int i = -1; // &r = 0; illegal
		const int &r = 0;

		// b
		int *const p2 = &i;

		// c
		const int ii = -1, &rr = 0;

		// d
		const int *const p3 = &i;

		// e
		const int *p1 = &i;

		// f
		// const int &const r2; illegal name
		const int &con = i;

		// g
		const int i2 = i, &r2 = i;

		return(0);
}
