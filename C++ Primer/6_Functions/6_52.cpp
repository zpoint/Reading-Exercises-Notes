#include <iostream>
void manip(int i, int j)
{
		std::cout << "Calling mainp: i: " << i << " j: " << j << std::endl;
}

double dobj = 3.0;

int main()
{
		std::cout << "manip('a', 'z'): " << std::endl;
		manip('a', 'z');
		std::cout << "manip(55.4, dobj): " << std::endl;
		manip(55.4, dobj);
		return 0;
}
