#include <iostream>
#include <memory>

int main()
{
		std::unique_ptr<int> iqtr(new int(3)), iqtr2;
		// iqtr2 = iqtr;
		std::unique_ptr<int> iqtr3(iqtr);
		return 0;
}
