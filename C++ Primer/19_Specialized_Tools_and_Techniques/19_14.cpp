#include <iostream>

typedef int cursor_t;

class Screen
{
		public:
				cursor_t get_cursor() const { return cursor; }
				cursor_t get() const { return this->get_cursor(); }
				cursor_t cursor;
};

int main()
{
		auto pmf = &Screen::get_cursor;
		pmf = &Screen::get;  // Ok, as long as get and get_cursor are same type 
		return 0;
}
