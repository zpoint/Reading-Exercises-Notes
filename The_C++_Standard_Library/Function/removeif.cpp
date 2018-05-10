#include <iostream>
#include <list>
#include <algorithm>
#include "../print.hpp"

/*
 * ERROR
 * A predicate should always be stateless
 */


class Nth
{
		// function object that returns true for the nth call
		private:
			int nth; // call for which return true
			int count; // call counter
		public:
			Nth(int n): nth(n), count(0) { }
			bool operator() (int)
			{
					return ++count = nth;
			}
};

int main()
{
		std::list<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		PRINT_ELEMENTS(coll, "coll       ");

		// remove third element
		std::list<int>::iterator pos;
		pos = std::remove_if(coll.begin(), coll.end(), Nth(3));
		coll.erase(pos, coll.end());
		PRINT_ELEMENTS(coll, "3rd removed");
		return 0;
}
