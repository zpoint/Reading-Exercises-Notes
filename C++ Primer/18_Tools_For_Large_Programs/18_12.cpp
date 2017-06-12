#include <iostream>
#include <string>

namespace chapter10 
{
		class TextQuery
		{
				public:
					TextQuery(std::string s): name(s) { }
					std::string name;
		};
}

namespace chapter15
{
		class Query
		{
				public:
					Query(std::string s): name(s) { }
					std::string name;
		};
}

int main()
{
		chapter10::TextQuery t10("t10");
		chapter15::Query q15("q15");
		std::cout << t10.name << std::endl << q15.name << std::endl;
		return 0;
}
