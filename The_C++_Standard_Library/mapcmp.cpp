#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

// function object to compare strings
// - allows you to set the comparison criterion at runtime
// - allows you to compare case insenstive

class RuntimeStringCmp
{
		public:
			// constants for the comparison criterion
			enum cmp_mode {normal, nocase};
		private:
			// actual comparsion mode
			const cmp_mode mode;

			// auxiliary function to compare case insensitive
			static bool nocase_compare(char c1, char c2)
			{
					return std::toupper(c1) < std::toupper(c2);
			}
		public:
			// constructor: initializes the comparsion criterion
			RuntimeStringCmp (cmp_mode m = normal): mode(m) { }

			// the comparsion
			bool operator() (const std::string& s1, const std::string &s2) const
			{
					if (mode == normal)
							return s1 < s2;
					else
							return std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), nocase_compare);
			}
};

// container type:
// - map with
// 		- string keys
// 		- string values
// 		- the special comparsion object type

typedef std::map<std::string, std::string, RuntimeStringCmp> StringStringMap;

// function that fills and prints sucn container
void fillAndPrint(StringStringMap& coll)
{
		// insert elements ain random order
		coll["Deutschland"] = "Germany";
		coll["deutsch"] = "German";
		coll["Haken"] = "snag";
		coll["arbeiten"] = "work";
		coll["Hund"] = "dog";
		coll["gehen"] = "go";
		coll["Unternehmen"] = "enterprise";
		coll["unternehmen"] = "undertake";
		coll["gehen"] = "walk";
		coll["Bestatter"] = "undertaker";

		// print elements
		std::cout.setf(std::ios::left, std::ios::adjustfield);
		for (const auto& elem : coll)
				std::cout << std::setw(15) << elem.first << " " << elem.second << std::endl;
		std::cout << std::endl;
}

int main()
{
		// create a container with the default comparison criterioon
		StringStringMap coll1;
		fillAndPrint(coll1);
		
		// create an object for case-insenstive comparisons
		RuntimeStringCmp ignorecase(RuntimeStringCmp::nocase);

		// create a container with the case-insensitive comparisons criterion
		StringStringMap coll2(ignorecase);
		fillAndPrint(coll2);
		return 0;
}
