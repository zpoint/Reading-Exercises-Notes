#include <iostream>

int main()
{
		std::range_error r("error");
		std::exception *p = &r;
		try
		{
				throw r;
		}
		catch (std::range_error e)
		{
				std::cout << "catch range_error" << std::endl;
				try
				{
						throw p;
				}
				catch (std::exception *e)
				{
						std::cout << "catch std::exception*" << std::endl;
				}
		}
		return 0;
}
				
