#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iterator>
#include "../print.hpp"

// class template for insert iterator for associative and unordered containers
template <typename Container>
class asso_insert_iterator: public std::iterator<std::output_iterator_tag, typename Container::value_type>
{
		protected:
			Container& container; // container in which elements are inserted

		public:
			// constructor
			explicit asso_insert_iterator (Container& c): container(c) { }

			// assignment operator
			// - inserts a value into the container
			asso_insert_iterator<Container>& operator=(const typename Container::value_type& value)
			{
					container.insert(value);
					return *this;
			}

			// deferencing is a no-op that retuens the iterator itself
			asso_insert_iterator<Container>& operator* ()
			{
					return *this;
			}

			// increment operation is a no-op that  returns the iterator itself
			asso_insert_iterator<Container>& operator++ ()
			{
					return *this;
			}

			asso_insert_iterator<Container>& operator++ (int)
			{
					return *this;
			}
};

// convenience function to create the inserter
template <typename Container>
inline asso_insert_iterator<Container> asso_inserter (Container& c)
{
		return asso_insert_iterator<Container>(c);
}

int main()
{
		std::unordered_set<int> coll;

		// create inserter for coll
		// - inconvenient way
		asso_insert_iterator<std::unordered_set<int>> iter(coll);

		// insert elements with the usual iterator interfance
		*iter = 1;
		iter++;
		*iter = 2;
		iter++;
		*iter = 3;

		PRINT_ELEMENTS(coll);

		// create inserter for coll and insert elements
		// - convenient way
		asso_inserter(coll) = 44;
		asso_inserter(coll) = 55;

		PRINT_ELEMENTS(coll);

		// use inserter with an algorithm
		std::vector<int> vals = { 33, 67, -4, 13, 5, 2 };
		std::copy(vals.begin(), vals.end(), asso_inserter(coll));
		PRINT_ELEMENTS(coll);

		return 0;
}
