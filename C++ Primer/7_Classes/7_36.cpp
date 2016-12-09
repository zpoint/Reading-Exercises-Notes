#include <iostream>

struct X {
		X (int i, int j): base(i), rem(base % j) {}
		int base, rem;  // exchange order of base and rem
};

int main()
{
		return 0;
}
