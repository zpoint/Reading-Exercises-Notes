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
			// constructor
			IntSequence (int initialValue): value(initialValue) { }

			// function call
			int operator() () 
			{ 
					return value++;
			}
};

int main()
{
		std::list<int> coll;
		IntSequence seq(1); // integral sequence starting with 1

		// insert values from 1 to 4
		// - pass function object by reference
		// so that it will continuw with 5
		std::generate_n<std::back_insert_iterator<std::list<int>>, int, IntSequence&>(std::back_inserter(coll), 4, seq);
		PRINT_ELEMENTS(coll);

		// insert value from 42 to 45
		std::generate_n(std::back_inserter(coll), 4, IntSequence(42));
		PRINT_ELEMENTS(coll);

		// continue with first sequence
		// - pass function object by value
		// so that it will continue with 5 again
		std::generate_n(std::back_inserter(coll), 4, seq);
		PRINT_ELEMENTS(coll);

		// continue with first sequence again
		std::generate_n(std::back_inserter(coll), 4, seq);
		PRINT_ELEMENTS(coll);
		return 0;
}
