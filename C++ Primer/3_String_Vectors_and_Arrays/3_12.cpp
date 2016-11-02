#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
int main()
{
		vector<vector<int>> ivec;
		// vector<string> svec = ivec; error different type
		vector<string> svec(10, "null");
		return(0);
}
