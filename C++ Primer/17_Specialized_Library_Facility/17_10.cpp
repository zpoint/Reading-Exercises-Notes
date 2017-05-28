#include <iostream>
#include <bitset>
#include <vector>

int main()
{
		std::vector<int> ivec{1, 2, 3, 5, 8, 13, 21};
		// a
		unsigned long long ull = 0;
		for (const int &i : ivec)
				ull |= 1 << i;
		std::bitset<sizeof(long long) * 8> vec_a(ull);
		std::cout << vec_a << std::endl;
		// b
		std::bitset<sizeof(long long) * 8> vec_b;
		for (const int &i : ivec)
				vec_b.set(i);
		std::cout << vec_b << std::endl;
		return 0;
}
