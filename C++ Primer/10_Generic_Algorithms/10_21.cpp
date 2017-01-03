#include <iostream>
#include <string>

int main()
{
		int s = 10;
		std::string word;
		auto f = [s] () mutable {
				std::cout << "Calling f, before procedure: s: " << s;
				if (s == 0)
				{
						std::cout << "\nAfter procedure, s: " << s << std::endl;
						return true;
				}
				else
						--s;

				std::cout << "\nAfter procedure, s: " << s << std::endl;
				return false;
		};

		while (true)
		{
				std::cout << f() << std::endl;
				std::cin >> word;
		}
		return 0;
}
