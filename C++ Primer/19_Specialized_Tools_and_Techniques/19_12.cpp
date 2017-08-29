#include <iostream>

class Screen
{
		public:
				int cursor;
};

int main()
{
		int Screen::*ptr_cursor;
		Screen s;
		ptr_cursor = &Screen::cursor;
		std::cout << s.*ptr_cursor << std::endl;
		return 0;
}
