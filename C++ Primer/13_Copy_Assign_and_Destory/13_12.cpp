#include <string>
#include <iostream>

class Sales_data {
		public:
				~Sales_data() { std::cout << "calling destructor!!" << std::endl; }
				std::string isbn() const { return ISBN; }
				std::string ISBN;
};

bool fcn(const Sales_data *trans, Sales_data accum)
{
		std::cout << "In function fcn" << std::endl;
		Sales_data item1(*trans), item2(accum);
		std::cout << "going out of fcn scope" << std::endl;
		return item1.isbn() != item2.isbn();
}

int main()
{
		std::cout << "In main" << std::endl;
		Sales_data test;
		Sales_data *ptr = &test;
		std::cout << "calling fcn" << std::endl;
		fcn(ptr, test);
		std::cout << "After fcn, going to return from main" << std::endl;
		return 0;
}
