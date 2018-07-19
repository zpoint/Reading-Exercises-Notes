#include <stdio.h>

#define Point3d_print_marco(pd) printf("( %g, %g, %g )", pd->x, pd->y, pd->z );

typedef struct point3d
{
		float x;
		float y;
		float z;
} Point3d;

void Point3d_print(const Point3d *pd)
{
		printf("( %g, %g, %g )", pd->x, pd->y, pd->z);
}

void my_foo()
{
		Point3d new_p3d;
		Point3d *pd = &new_p3d;
		/* print the point directory ... */
		printf("( %g, %g, %g )", pd->x, pd->y, pd->z);
}

int main()
{
		return 0;
}
