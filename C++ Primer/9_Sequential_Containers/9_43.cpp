#include <iostream>
#include <string>

int main()
{
		std::string strings, s, oldVal, newVal;
		oldVal = "tho, thru 123";
		s = "thru";
		newVal = "through";
		std::string::iterator oiter = oldVal.begin();
		while (oiter != oldVal.end())
		{
				// slow algorithms
				auto iter = oiter;
				auto subiter = s.begin();
				for (; *iter == *subiter; ++iter, ++subiter);
				if (subiter == s.end())
				{
						iter = oldVal.erase(oiter, iter);
						oldVal.insert(iter, newVal.cbegin(), newVal.cend());
						break;
				}
				++oiter;
		}
		std::cout << oldVal << std::endl;
		return 0;
}
