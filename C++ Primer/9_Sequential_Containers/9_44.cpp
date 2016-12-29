#include <iostream>
#include <string>

int main()
{
		std::string strings, s, oldVal, newVal;
		oldVal = "tho, thru 123";
		s = "thru";
		newVal = "through";
		for (decltype(oldVal.size()) i = 0; i < oldVal.size() - s.size(); ++i)
		{
				decltype(oldVal.size()) j = 0;
				for (; j < s.size(); ++j)
				{
						if (oldVal[i + j] != s[j])
								break;
				}
				if (j == s.size())
				{
						oldVal.replace(i, s.size(), newVal);
						break;
				}
		}


		std::cout << oldVal << std::endl;
		return 0;
}
