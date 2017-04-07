#include <iostream>
#include <vector>

class NoDefault
{
		public:
			NoDefault(int) { }
};


int main()
{
		std::vector<NoDefault> nd;
		return 0;
}
