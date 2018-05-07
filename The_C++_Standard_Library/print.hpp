#include <iostream>

template <typename T>
void PRINT_ELEMENTS(const T& CONTAINER, const std::string& val="")
{
		std::cout << val << ": ";
		for (const auto &elem : CONTAINER)
				std::cout << elem << " ";
		std::cout << std::endl;
}
