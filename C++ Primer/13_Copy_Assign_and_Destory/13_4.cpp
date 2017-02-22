#include <iostream>

class Point {
		public:
				Point(const Point &p) {std::cout << "Copy constructor " << std::endl;}
				Point() {std::cout << "default constructor" << std::endl; }
};

Point global;
Point foo_bar(Point arg)
{
		std::cout << "first line of function: foo_bar" << std::endl;
		Point local = arg;
		std::cout << "After: Point local = arg;" << std::endl;
		Point *heap = new Point(global);
		std::cout << "After: Point *heap = new Point(global);" << std::endl;
		*heap = local;
		std::cout << "After: *heap = local" << std::endl;
		Point pa[4] = {local, *heap};
		std::cout << "After: Point pa[4] = " << std::endl;
		std::cout << "Going to return *heap" << std::endl;
		return *heap;
}


int main()
{
		std::cout << "In main, going to call foo_bar(global);" << std::endl;
		foo_bar(global);
		return 0;
}
