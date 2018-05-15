#include "algostuff.hpp"

int main()
{
		/*
		 * https://stackoverflow.com/questions/11483060/stdnext-permutation-implementation-explanation
		 */
		std::vector<int> coll;
		INSERT_ELEMENTS(coll, 1, 3);
		PRINT_ELEMENTS(coll, "on entry:  " );

		// permute elements until they are sorted
		// - run through all permutations because the elements are sorted now
		while (std::next_permutation(coll.begin(), coll.end()))
				PRINT_ELEMENTS(coll, " ");

		PRINT_ELEMENTS(coll, "afterward: ");

		// permute until descending sorted
		// - this is the next permutation after ascending sorting
		// - so the loop ends immediately
		while (std::prev_permutation(coll.begin(), coll.end()))
				PRINT_ELEMENTS(coll, " ");

		PRINT_ELEMENTS(coll, "now:       ");

		// permute elements until they are sorted in descending order
		// - run through all permutations because the elements are sorted in descending order now
		while (std::prev_permutation(coll.begin(), coll.end()))
				PRINT_ELEMENTS(coll, " ");

		PRINT_ELEMENTS(coll, "afterward: ");

		return 0;
}
