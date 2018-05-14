#include "algostuff.hpp"

int main()
{
		std::array<int, 10> coll;

		std::iota(coll.begin(), coll.end(), 42);

		PRINT_ELEMENTS(coll, "coll:  ");
		return 0;
}
