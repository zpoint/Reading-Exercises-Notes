#include <iostream>

int main(int argc, char **argv)
{
		while (*argv++ != nullptr)
				std::cout << *argv << std::endl;
		return 0;
}
