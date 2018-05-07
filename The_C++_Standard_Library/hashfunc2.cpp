#include <string>
#include <iostream>
#include <unordered_set>
#include "hashval.hpp"
#include "print.hpp"

class Customer
{
		private:
			std::string fname;
			std::string lname;
			long no;
		public:
			Customer (const std::string& fn, const std::string& ln, long n): fname(fn), lname(ln), no(n) { }
			std::string firstname() const
			{
					return fname;
			}
			std::string lastname() const
			{
					return lname;
			}
			long number() const
			{
					return no;
			}
			friend std::ostream& operator<< (std::ostream& strm, const Customer& c)
			{
					return strm << "[" << c.fname << "," << c.lname << "," << c.no << "]";
			}
};

int main()
{
		// lambda for user-defined hash function
		auto hash = [] (const Customer& c) { return hash_val(c.firstname(), c.lastname(), c.number()); };
		
		// lambda for user-defined equality criterion
		auto eq = [] (const Customer& c1, const Customer& c2)
		{
				return c1.number() == c2.number();
		};

		// create unordered set with user-defined behaviour
		std::unordered_set<Customer, decltype(hash), decltype(eq)> custset(10, hash, eq);
		custset.insert(Customer("nico", "josuttis", 42));
		PRINT_ELEMENTS(custset);
		return 0;
}

