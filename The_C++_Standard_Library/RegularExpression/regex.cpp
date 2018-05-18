#include <regex>
#include <iostream>

void out(bool b)
{
		std::cout << (b ? "found" : "not found") << std::endl;
}

int main()
{
		// find XML/HTML-tagged value (using default syntax):
		std::regex reg1("<.*>.*</.*>");
		bool found = std::regex_match("<tag>value</tag>", reg1);
		out(found);

		// find XML/HTML-tagged value (tags before and after the value must match):
		std::regex reg2("<(.*)>.*</\\1>");
		found = std::regex_match("<tag>value</tag>", reg2);
		out(found);

		// find XML/HTML-tagged value (using grep syntax):
		std::regex reg3("<\\(.*\\)>.*</\\1>", std::regex_constants::grep);
		found = std::regex_match("<tag>value</tag>", reg3);
		out(found);

		// use C-string as regular expression (needs explicit cast to regex):
		found = std::regex_match("<tag>value</tag>", std::regex("<(.*)>.*</\\1>"));
		out(found);
		std::cout << std::endl;

		// regex_match() versus regex_search()
		found = std::regex_match("XML tag: <tag>value</tag>", std::regex("<(.*)>.*</\\1>")); // fails to match
		out(found);
		found = std::regex_match("XML tag: <tag>value</tag>", std::regex(".*<(.*)>.*</\\1>.*")); // matches
		out(found);
		found = std::regex_search("XML tag: <tag>value</tag>", std::regex("<(.*)>.*</\\1>")); // matches
		out(found);
		found = std::regex_search("XML tag: <tag>value</tag>", std::regex(".*<(.*)>.*</\\1>.*")); // matches
		out(found);

		return 0;
}
