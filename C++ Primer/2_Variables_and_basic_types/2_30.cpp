#include <iostream>

int main()
{
		const int v2 = 0; // top level
		int v1 = v2;
		int *p1 = &v1, &r1 = v1;
		const int *p2 = &v2, *const p3 = &v1, &r2 = v2; //  p2 low-level, p3 top-level and low-level, r2 low-level
		return(0);
}
