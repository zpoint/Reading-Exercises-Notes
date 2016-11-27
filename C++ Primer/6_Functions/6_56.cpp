#include <iostream>
#include <vector>

int ifun(int i, int j)
{
		std::cout << "I am " << __func__ << " " << i << " " << j << std::endl;
		return i;
}

int add(int i, int j)
{
		std::cout << "I am " << __func__ << " " << i << " " << j << std::endl;
		return i + j;
}

int subtract(int i, int j)
{	
		std::cout << "I am " << __func__ << " " << i << " " << j << std::endl;
		return i - j;
}

int multiply(int i, int j)
{
		std::cout << "I am " << __func__ << " " << i << " " << j << std::endl;
		return i * j;
}

int divide(int i, int j)
{

		std::cout << "I am " << __func__ << " " << i << " " << j << std::endl;
		return static_cast<int>(static_cast<double>(i) / static_cast<double>(j));
}

int main()
{
		std::vector<int (*)(int, int)> ifunc_vec(10, ifun);
		ifunc_vec[0] = ifun;
		ifunc_vec[1] = add;
		ifunc_vec[2] = subtract;
		ifunc_vec[3] = multiply;
		ifunc_vec[4] = divide;
		int a[10] = {1, 10};
		for (auto &i : ifunc_vec)
		{
				std::cout << "Address: " << &i << std::endl;
				std::cout << i(a[0], a[1]) << std::endl;
		}
		return 0;
}
