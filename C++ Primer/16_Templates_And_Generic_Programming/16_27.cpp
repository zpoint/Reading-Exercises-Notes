#include <iostream>
#include <string>

template <typename T> class Stack { 
	
};

void f1(Stack<char>) {  }  // no initilized

class Exercise
{
		Stack<double> &rsd; // no initilized
		Stack<int> si;  // no initilized
};


int main()
{
		Stack<char> *sc;
		f1(*sc);
		int iObj = sizeof(Stack<std::string>);
		return 0;
}
