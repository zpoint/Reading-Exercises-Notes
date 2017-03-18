#include <iostream>

struct LongDouble {
		LongDouble(double v = 0.0): val(v) { }
		operator double() const { std::cout << "Double converter" << std::endl; return val; }
		operator float() const { std::cout << "Float converter" << std::endl; return float(val); }
		private:
			double val;
};

int main()
{
		LongDouble lobj;
		// int ex1 = lobj; error, ambigious
		float ex2 = lobj;
		return 0;
}	
