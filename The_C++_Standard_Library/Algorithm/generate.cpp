#include <cstdlib>
#include "algostuff.hpp"

int main()
{
		std::list<int> coll;

		// insert five random numbers
		std::generate_n(std::back_inserter(coll),
						5,
						rand);
		PRINT_ELEMENTS(coll);

		// overwrite with five new random numbers
		std::generate(coll.begin(), coll.end(), rand);
		PRINT_ELEMENTS(coll);

		return 0;
}
