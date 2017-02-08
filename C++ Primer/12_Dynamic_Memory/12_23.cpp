#include <iostream>
#include <string>
#include <memory>

int main()
{
		// question 1
		char str1[] = "abcd", str2[] = "efgh";
		std::size_t size = sizeof(str1) + sizeof(str2) - 1; // minute a nullpt
		std::size_t len_str1 = sizeof(str1) - 1;
		std::unique_ptr<char []> c_array(new char[size]);
		for (std::size_t index = 0; index < size; ++index)
		{
				if (index < len_str1)
						c_array[index] = str1[index];
				else
						c_array[index] = str2[index - len_str1];
		}

		for (std::size_t index = 0; index < size; ++index)
				std::cout << c_array[index];
		std::cout << std::endl;

		// question 2
		std::string str3("str3"), str4("str4");
		std::size_t size2 = str3.size() + str4.size();
		std::unique_ptr<char []> c2_array(new char[size2]);
		for (std::size_t index = 0; index < size2; ++index)
		{
				if (index < str3.size())
						c2_array[index] = str3[index];
				else
						c2_array[index] = str4[index - str3.size()];
		}
		for (std::size_t index = 0; index < size2; ++index)
				std::cout << c2_array[index];
		std::cout << std::endl;
		return 0;
}
