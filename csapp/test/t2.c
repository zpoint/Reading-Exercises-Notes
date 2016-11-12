#include "show_byte.c"
int main(void)
{
	printf("0x%x\n",saturating_add(0xb1234567,0xb1237658));
	printf("0x%x\n",saturating_add(0x76578ac3,0x7a239876));
}
