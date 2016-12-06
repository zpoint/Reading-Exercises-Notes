#include <ostream>
#include <string>

class Screen {
		public:
				typedef std::string::size_type pos;
				Screen() = default;
				Screen(pos hei, pos wid): height(hei), width(wid) {}
				Screen(pos hei, pos wid, char c): height(hei), width(wid), contents(hei * wid, c) {}
		private:
				pos cursor = 0;
				pos height = 0, width = 0;
				std::string contents;
};


int main()
{
		return 0;
}
