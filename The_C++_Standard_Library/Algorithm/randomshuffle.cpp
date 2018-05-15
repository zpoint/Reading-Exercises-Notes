#include <cstdlib>
#include <random>
#include "algostuff.hpp"

class MyRandom
{
		public:
			ptrdiff_t operator() (ptrdiff_t max)
			{
					double tmp;
					tmp = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
					std::cout << "RAND_MAXi: " << RAND_MAX << " max: " << max << " tmp:  " << tmp << " tmp * max: " << tmp * max << std::endl;
					return static_cast<ptrdiff_t>(tmp * max);
			}
};

int main()
{
		std::vector<int> coll;

		INSERT_ELEMENTS(coll, 1, 9);
		PRINT_ELEMENTS(coll, "coll:        ");

		// shuffle elements with self-written random-number generator
		MyRandom rd;
		std::random_shuffle(coll.begin(), coll.end(), rd);
		PRINT_ELEMENTS(coll, "shuffled:     ");
		return 0;
}

