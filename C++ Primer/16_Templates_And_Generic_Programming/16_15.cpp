#include <iostream>

template <unsigned N, unsigned M> class Screen
{
		public:
			Screen(): width(N), height(M) { }
			friend std::ostream& operator<<(std::ostream &os, const Screen &s) 
			{ os << "width: " << s.width << " height: " << s.height << std::endl; return os; };
			friend std::istream& operator>>(std::istream &is, Screen &s) { is >> s.width >> s.height; return is; }
			unsigned get_with() { return width; }
		private:
			unsigned width;
			unsigned height;
};


int main()
{
		Screen<1, 2> s;
		std::cout << s;
		return 0;
}
