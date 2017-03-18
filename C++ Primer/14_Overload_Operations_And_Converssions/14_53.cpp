#include <iostream>

class SmallInt
{
		friend SmallInt operator+(const SmallInt&, const SmallInt&);
		public:
			SmallInt(int i = 0): val(i)
			{
					if (i < 0 || i > 255)
							throw std::out_of_range("Bad SmallInt value");
			}
			operator int() const { return val; }
		private:
			std::size_t val;
};

SmallInt operator+(const SmallInt &s1, const  SmallInt& s2)
{
		std::cout << "Calling operator+(const SmallInt &s1, const SmallInt &s2)" << std::endl;
		return s1.val + s2.val;
}

int main()
{
		SmallInt s1;
		double d = s1 + 3.14;  // int + double or SmallInt& + SmallInt&
		return 0;
}
