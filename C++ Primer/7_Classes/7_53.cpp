#include <iostream>

class Debug {
		constexpr Debug(bool b = true): hw(b), io(b), other(b) { }
		constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o) { }
		void set_io(bool b) { io = b; }
		void set_hw(bool b) { hw = b; }
		void set_other(bool b) { other = b; }
		bool hw;
		bool io;
		bool other;
};

int main()
{
		return 0;
}
