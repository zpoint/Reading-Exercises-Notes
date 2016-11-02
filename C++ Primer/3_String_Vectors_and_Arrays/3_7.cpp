#include <iostream>
#include <string>
using std::string;
using std::cin; using std::cout; using std::endl;

int main()
{
		string str;
		cout << "Enter a string, change every character to X" << endl;
		cin >> str;
		for (auto c : str) // remain unchanged
				c = std::toupper(c);
		cout << str << endl;
		return(0);
}
