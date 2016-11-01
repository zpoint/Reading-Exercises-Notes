#include <iostream>

int main()
{
		const int v2 = 0; // top level
		int v1 = v2;
		int *p1 = &v1, &r1 = v1;
		const int *p2 = &v2, *const p3 = &v1, &r2 = v2; //  p2 low-level, p3 top-level and low-level, r2 low-level
		r1 = v2; // legal
		// p1 = p2; // not legal, pi should be const
		p2 = p1; // legal
		// p1 = p3; not legal, same as p1 = p2
		p2 = p3; // legal 
		return(0);
}
