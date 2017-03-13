#include <iostream>

class test {
		public:
				int operator()(bool t, int sec, int third) const
				{
						if (t)
								return sec;
						else
								return third;
				}
};

int main()
{
		test t;
		std::cout << t(1 + 1 > 2, 1, 0) << std::endl;
		return 0;
}
