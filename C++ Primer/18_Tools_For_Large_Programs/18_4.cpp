#include <iostream>

int main()
{
		try
		{
				std::cout << "Inside try! " << std::endl;
		}
		catch (std::overflow_error)
		{
				std::cout << "Overflow error " << std::endl;
		}
		catch (...)
		{
				std::cout << "In catch exception " << std::endl;
				throw;
		}
		return 0;
}
