#include <iostream>
#include <string>
using std::string;
using std::cin; using std::cout; using std::endl;

int main()
{
		string str, tmp;
		cout << "Enter a string, change every character to X" << endl;
		cin >> str;
		tmp = str;
		std::string::size_type i = 0;
		while (i < str.size())
				str[i] = std::toupper(str[i++]);
		cout << "After while loop: " << str << endl;

		str = tmp;
		for (auto &c : str)
				c = std::toupper(c);
		cout << "After for loop: " << str << endl;
		// Perfer for loop, simpler
		return(0);
}
