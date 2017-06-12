#include <iostream>

namespace mathLib
{
		namespace MatrixLib
		{
				class matrix
				{
						public:
							matrix(int value): val(value) { }
							int val;
				};
				matrix operator*(const matrix &m1, const matrix &m2)
				{
						return matrix(m1.val * m2.val);
				}
		}
}


int main()
{
		mathLib::MatrixLib::matrix m1(1), m2(2);
		std::cout << (m1 * m2).val << std::endl;
		return 0;
}
