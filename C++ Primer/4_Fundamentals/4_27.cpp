#include <iostream>

int bin_buf[32];
void pr_binaryInt(int x)
{
		int count = 0, remain = 0, result = x;
		bool negative = false;
		if (x < 0)
		{
				x = -x;
				negative = true;
				result = x;
		}
		while (count < 32)
		{
				remain = result % 2;
				result /= 2;
				bin_buf[32 - count++ - 1] = remain;
		}
		if (negative)
		{
				for (auto &item  : bin_buf)
				{
						if (item == 1)
								item = 0;
						else
								item = 1;
				}
				// add 1
				int index = 31;
				while (index >= 0 && bin_buf[index] == 1)
						bin_buf[index--] = 0;
				bin_buf[index] = 1;
		}
		// print binary
		std::cout << (negative ? -x : x) << " in binary form: ";
		for (auto i = 0; i < 32; i++)
		{
				if (i % 4 == 0 && i != 0)
						std::cout << " ";
				std::cout << bin_buf[i];
		}
		std::cout << std::endl;
}
int main()
{
		unsigned long ul1 = 3, ul2 = 7;
		// ul1: ... 0011
		// ul2: ... 0111
		pr_binaryInt(ul1 & ul2); // ... 0011
		pr_binaryInt(ul1 | ul2); // ... 0111
		pr_binaryInt(ul1 && ul2); // ... 0001
		pr_binaryInt(ul1 || ul2); // ... 0001
		return(0);
}

