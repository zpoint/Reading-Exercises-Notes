#include <stdio.h>
#include <limits.h>
#define WORD_SIZE = sizeof(long) << 3;
typedef unsigned char *byte_pointer;

void show_byte(byte_pointer start,int len)
{
	for(int i=0;i<len;i++)
		printf("%.2x ",start[i]);
	printf("\n");
}

void show_int(int n)
{
	show_byte((byte_pointer)&n,sizeof(int));
}

void show_long(long n)
{
	show_byte((byte_pointer)&n,sizeof(long));
}

void show_float(float n)
{
	show_byte((byte_pointer)&n,sizeof(float));
}

void show_double(double n)
{
	show_byte((byte_pointer)&n,sizeof(double));
}

void show_pointer(void *n)
{
	show_byte((byte_pointer)&n,sizeof(void*));
}


int is_big_endian(void)
{
	unsigned int i = 1;
	return *((char *)&i);
}


int consist(int x,int y)
{
	int i = x;
	*(byte_pointer)&i = *(byte_pointer)&y;
	return i;	
}

unsigned replace_byte(unsigned x,int i,unsigned char b)
{
	*((byte_pointer)&x + i) = b;
	return x;
}


//int xeq10_xeq0_xleasteq1_xmosteq0(int x)
//{
	// A(any bit of x equals 1):
	//return 0 | x;
	
	// B(any bit of x equals 0):
	//return (-INT_MAX-1) ^ x;
	
	// C(any bit in the least significant byte of x equals 1):
	//return 1 & x;
	
	// D(any bit in the most significant byte of x equals 1):
	//return INT_MIN & x; 
//}

int int_shifts_are_arithnetic(void)
{
	//yield 1 when arithmetic right shift
	int x = -1;
	return (x>>1) == -1; 
}

int sra(unsigned x,int k)
{
	int xsrl = (unsigned) x >> k, w = sizeof(int) << 3;
	unsigned z = 1 << (w-k-1), mask = z - 1;
	unsigned right = mask & xsrl;
	unsigned left = ~mask & (~(z & xsrl) + z);
	return left | right;
}

unsigned srl(unsigned x, int k)
{
	unsigned xsra = (int)x >> k, w = sizeof(int) << 3;
	unsigned z = 1 << (w - k);
	return (z - 1) & xsra;
}

int any_odd_one(unsigned x)
{
	//assume w =32;
	//return 1 when any odd bit of x = 1, 0 otherwise;
	return x & 0x55555555;
}

int odd_ones(unsigned x)
{
	x ^= (x >> 16);
	x ^= (x >> 8);
	x ^= (x >> 4);
	x ^= (x >> 2);
	x ^= (x >> 1);
	return x & 1;
}

int leftmost_one(unsigned x)
{
	/*Generate mask indicating leftmost 1 in x, Assume w = 32 */
	x |= (x >> 1);
	x |= (x >> 2);
	x |= (x >> 4);
	x |= (x >> 8);
	x |= (x >> 16);
	return x ^ (x >> 1);
}

int lower_one_mask(int n)
{
	/* Mask with least significant n bits set to 1 
	   Assume w = 32
	*/
	int x = -1;
	return (unsigned)x >> (32 - n);
}

unsigned rotate_left(unsigned x, int n)
{
	// Do rotating left shift, Assume 0 <= n < w
	int left = (sizeof(int) << 3) - n;
	unsigned mask = ~((1 << left) - 1);
	mask &= x;
	x <<= n;
	return x | (mask >> left);
}

int fits_bits(int x,int n)
{
	//
	return !!(x >> n);
}

int saturating_add(int x,int y)
{
	//Addition that saturates to TMin or Tmax
	int w = sizeof(int) << 3;
	int t = x + y;
	int ans = x + y;
	x >>= (w - 1);
	y >>= (w - 1);
	t >>= (w - 1);
	int pos_ovf = (~x & ~y & t);
	int neg_ovf = (x & y & ~t);
	int novf = ~(pos_ovf|neg_ovf);
	return (pos_ovf & INT_MAX) | (neg_ovf & INT_MIN) | (novf & ans);
}

unsigned int unsigned_high_prod(unsigned x,unsigned y)
{
	int w = sizeof(int) << 3;
	return signed_high_prod(x,y) + (x >> (w - 1))*y + (y >> (w - 1)) * x;
}

int decode2(int x, int y, int z)
{
	int a = y - z;
	return (a << 31) >> 31 ^ x;
}


