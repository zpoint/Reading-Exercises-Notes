#include <iostream>

int main()
{
		// a
		int i, *const cp = &i; // cp should be initilized

		// b
		int *p1, *const p2 = &i; // same

		// c
		const int ic = i, &r = ic; // const variale should be initilized

		// d
		const int *const p3 = &i; // initilized

		// e
		const int *p;	
		return(0);
}
