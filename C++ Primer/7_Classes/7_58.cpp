#include <iostream>
#include <vector>

class Example {
		public:
				static double rate;
				static const int vecSize;
			   	static std::vector<double> vec;
};


const int Example::vecSize = 20;
double Example::rate = 3;
std::vector<double> Example::vec(vecSize);
int main()
{
		std::vector<int> ivec(30);
		Example e;
		std::cout << e.vecSize << std::endl;
		std::cout << e.rate << " " << e.vec.size() << std::endl;
		return 0;
}
