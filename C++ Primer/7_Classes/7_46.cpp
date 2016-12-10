#include <iostream>
class a {
		// compiler provide it for you
};

class b {
		public:
				b(int i = 3, int j = 4): b1(i), b2(j) { } // default constructor
				int b1, b2;
};

class c {
		// always privode it is a good habit
};

class d {
		public:
				d(int i): d1(i) { }
				d() = default; // you must provide default constructor if you have other constructor, or compiler will complain
				int d1;
};


int main()
{
		a ca;
		b cb;
		c cc;
		d cd;
		return 0;
}
