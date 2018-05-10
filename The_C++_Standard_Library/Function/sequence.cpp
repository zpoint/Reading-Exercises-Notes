#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include "../print.hpp"

class IntSequence
{
		private:
			int value;
		public:
			IntSequence (int initValue): value(initValue) { }

			int operator() () { return value++; }
};

int main()
{
		std::list<int> coll;

		// insert values from 1 to 9
		std::generate_n(std::back_inserter(coll), // start
					   	9, // number of elements
						IntSequence(1)); // generates values, starting with 1

		PRINT_ELEMENTS(coll);

		// replace second to last element but one with values starting at 42
		std::generate(std::next(coll.begin()), std::prev(coll.end()), IntSequence(42));

		PRINT_ELEMENTS(coll);

		return 0;
}
