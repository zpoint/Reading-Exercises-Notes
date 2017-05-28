#include <bitset>
#include <iostream>
#include <string>

template <size_t N>
void pr_bitset(std::bitset<N> bset)
{
		std::cout << bset.size() << " ";
		std::cout << bset;
		std::cout << std::endl;
}

int main()
{
		std::bitset<64> bitvec(32);
		pr_bitset(bitvec);
		std::bitset<32> bv(1010101);
		pr_bitset(bv);

		std::string bstr;
		std::cin >> bstr;
		std::bitset<8> bv2(bstr);
		pr_bitset(bv2);
		std::cout << sizeof(long) << " " << sizeof(long long) << std::endl;
		return 0;
}
