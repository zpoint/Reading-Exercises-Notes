#include <unordered_set>
#include <string>
#include <iostream>
#include "hashval.hpp"

template <typename T>
void PRINT_ELEMENTS(const T& container, const std::string& val="")
{
		std::cout << val << ": ";
		for (const auto& item : container)
				std::cout << item << " ";
		std::cout << std::endl;
}

class Customer
{
		private:
			std::string fname;
			std::string lname;
			long no;
		public:
			Customer (const std::string& fn, const std::string& ln, long n): fname(fn), lname(ln), no(n) { }
			friend std::ostream& operator<< (std::ostream& strm, const Customer& c)
			{
					return strm << "[" << c.fname << "," << c.lname << "," << c.no << "]";
			}
			friend class CustomHash;
			friend class CustomEqual;
};

class CustomHash
{
		public:
			std::size_t operator() (const Customer& c) const
			{
					return hash_val(c.fname, c.lname, c.no);
			}
};

class CustomEqual
{
		public:
			bool operator() (const Customer& c1, const Customer& c2) const
			{
					return c1.no == c2.no;
			}	
};

int main()
{
		// unordered set with own hash function and equivalence criterion
		std::unordered_set<Customer, CustomHash, CustomEqual> custset;

		custset.insert(Customer("nico", "josuttis", 42));
		PRINT_ELEMENTS(custset);

		return 0;
}

