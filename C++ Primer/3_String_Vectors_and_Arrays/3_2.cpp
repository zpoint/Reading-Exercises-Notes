#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl; using std::getline; using std::string;
int main()
{
		string line;
		cout << "One line at a time, empty line to next" << endl;
		while (getline(cin, line))
		{
				if (line.size() == 0)
						break;
				cout << line << std::endl;
		}
		cout << "One word at a time, Send a signal to terminate" << endl;
		while (cin >> line)
				cout << line << std::endl;
		return(0);
}
