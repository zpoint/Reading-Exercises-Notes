#include <iostream>

class X {
		int i;
		class Y *ptr_to_y;
};

class Y {
		X xobj;
};



int main()
{
		X xobj;
		Y yobj;
		return 0;
}
