#include <iostream>

class Screen
{
		public:
		void a() { std::cout << "a" << std::endl; }
		void b(int) { std::cout << "b" << std::endl; }
};

int main()
{
		using A = void (Screen::*)();
		using B = void (Screen::*)(int);
		Screen s;
		A f_a = &Screen::a;
		B f_b = &Screen::b;
		(s.*f_a)();
		(s.*f_b)(1);
		return 0;
}
