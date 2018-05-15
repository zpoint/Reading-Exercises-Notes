#include "algostuff.hpp"

bool lessLength (const std::string& s1, const std::string& s2)
{
		return s1.length() < s2.length();
}

int main()
{
		// fill two collections with same elements
		std::vector<std::string> coll1 = { "1xxx", "2x", "3x", "4x", "5xx", "6xxxx",
										   "7xx",  "8xxx", "9xx", "10xxx", "11", "12", "13", "14xx", "15", "16", "17"	
										};
		std::vector<std::string> coll2(coll1);

		PRINT_ELEMENTS(coll1, "on entry:\n ");
		
		// sort (according to the length of the string)
		std::sort(coll1.begin(), coll1.end(), lessLength);
		std::stable_sort(coll2.begin(), coll2.end(), lessLength);

		PRINT_ELEMENTS(coll1, "\nwith sort():\n ");
		PRINT_ELEMENTS(coll2, "\nstable_sort():\n ");
		return 0;
}
