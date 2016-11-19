#include <iostream>

void *get(int &a, const char c)
{
		while (1)
		{
				std::cin >> a;
				if (std::cin.fail())
				{
						std::cout << "Invalid input for " << c << " , Please enter an integer" << std::endl;
						std::cin.clear();
						std::cin.ignore(BUFSIZ, '\n');
				}
				else
						break;
		}
		return(nullptr);
}

void getall(int &a, int &b, int &c, int &d)
{
		get(a, 'a');
		get(b, 'b');
		get(c, 'c');
		get(d, 'd');
}

int main()
{
		int a, b, c, d;
		std::cout << "Enter 4 integers for a, b, c, d. I will check whether a > b and b > c and c > d" << std::endl;
		getall(a, b, c, d);
		while (!(a > b && b > c && c > d))
		{
				std::cout << "Incorrect, Please make sure a > b && b > c && c > d" << std::endl;
				getall(a, b, c, d);
		}
		std::cout << "Bingo!" << std::endl;
		return(0);
}
