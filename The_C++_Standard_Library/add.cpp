#include <list>
#include <algorithm>
#include <iostream>

class AddValue
{
		private:
			int theValue;
		public:
			AddValue(int v): theValue(v) {}
			void operator() (int& elem) const { elem += theValue; }
};

template <typename T>
void PRINT_ELEMENTS(const T& CONTAINER, const std::string val="")
{
		std::cout << val << ": ";
		for (const auto& i: CONTAINER)
				std::cout << i << " ";
		std::cout << std::endl;
}

int main()
{
		std::list<int> coll;

		for (int i=1; i<=9; ++i)
				coll.push_back(i);

		PRINT_ELEMENTS(coll, "initialized:\t");
		std::for_each(coll.begin(), coll.end(), AddValue(10));
		PRINT_ELEMENTS(coll, "after adding 10:\t");
		std::for_each(coll.begin(), coll.end(), AddValue(*coll.begin()));
		PRINT_ELEMENTS(coll, "after adding first element: ");
		return 0;
}
