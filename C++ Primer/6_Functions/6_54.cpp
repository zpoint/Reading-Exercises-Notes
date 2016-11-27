#include <iostream>
#include <vector>

int ifun(int i, int j)
{
		std::cout << "I am " << __func__ << " " << i << " " << j << std::endl;
		return i;
}

int main()
{
		std::vector<int (*)(int, int)> ifunc_vec(10, ifun);
		int a[10] = {10, 1};
		for (auto i : ifunc_vec)
				i(a[0], a[1]);
		return 0;
}
