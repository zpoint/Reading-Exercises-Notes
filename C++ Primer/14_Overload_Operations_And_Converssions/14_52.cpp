#include <iostream>

class SmallInt {
		public:
			SmallInt(int i = 0):val(i)
			{
					if (i < 0 || i > 255)
						throw std::out_of_range("Bad SmallInt value");
			}
		operator int() const { return val; }
		private:
			std::size_t val;
};

struct LongDouble {
		LongDouble(double v = 0.0): val(v) { }
		operator double() const { std::cout << "Double converter" << std::endl; return val; }
		operator float() const { std::cout << "Float converter" << std::endl; return float(val); }
		
		LongDouble operator+(const SmallInt&)
		{
				std::cout << "Calling member function LongDouble operator+(const SmallInt&)" << std::endl;
				return *this;
		}
		
		private:
			double val;
};

LongDouble operator+(LongDouble &ld, double)
{
		std::cout << "Calling non member function LongDouble operator+(LongDouble &ld, double)" << std::endl;
		return ld;
}

int main()
{
		LongDouble ld;
		SmallInt si;
		ld = si + (float)ld; // int + double or int + float
		ld = ld + si; // double + int or float + int or LongDouble + double
		return 0;
}	
