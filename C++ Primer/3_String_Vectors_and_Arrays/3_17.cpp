#include <iostream>
#include <string>
#include <vector>
using std::vector; using std::string;
using std::cout; using std::cin; using std::endl;

int main()
{
		int val;
		string str;
		cout << "Enter the count of the string you are going to enter" << endl;
		cin >> val;
		while (val <= 0)
		{
				if (cin.fail())
				{
						cin.clear();
						cin.ignore(BUFSIZ, '\n');
						cout << "invalid input" << endl;
				}
				else
						cout << "invalid count: " << val << " reenter again" << endl;
				cin >> val;
		}
		cout << "Now enter " << val << " strings" << endl;
		vector<string> vec_str;
		for (auto i = 0; i < val; i++)
		{
				cin >> str;
				vec_str.push_back(str);
		}

		cout << "\nIterate your vector: \n";
		for (auto &item : vec_str)
		{
				for (auto &c : item)
						c = std::toupper(c);
				cout << item << endl;
		}
		return(0);
}
