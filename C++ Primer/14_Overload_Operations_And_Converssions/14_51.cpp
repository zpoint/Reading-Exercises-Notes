#include <iostream>

struct LongDouble {
		LongDouble(double v = 0.0): val(v) { }
		operator double() const { std::cout << "Double converter" << std::endl; return val; }
		operator float() const { std::cout << "Float converter" << std::endl; return float(val); }
		private:
			double val;
};

void calc(int)
{
		std::cout << "Calling int version of calc" << std::endl;
}

void calc(LongDouble)
{
		std::cout << "Calling LongDouble of calc" << std::endl;
}

int main()
{
		double dval;
		calc(dval);
		return 0;
}	
