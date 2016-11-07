#include <iostream>

int main()
{
		int result = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2;
		int result2 = ((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2);
		std::cout << "result: " << result << " result2: " << result2 << std::endl;
		return(0);
}
