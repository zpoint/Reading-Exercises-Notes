#include "show_byte.c"

int main(void)
{
	int i;
	printf("Enter an integer,I will show the bytes in hexdecimal:\n");
	scanf("%d",&i);
	printf("You entered %d\n\n",i);

	printf("int\n");
	show_int(i);

	printf("long\n");
	show_long((long)i);

	printf("pointer to int\n");
	show_pointer(&i);

	printf("\nfloat:%f\n\n",(float)i);
	show_float((float)i);

	printf("\ndouble:%f\n\n",(double)i);
	show_double((double)i);	
}
