#include <iostream>
#include <vector>

struct X {
		X() { std::cout << "calling constructor X() " << std::endl;}
		X(const X&) { std::cout << "copy constructor X(const X&)" << std::endl;}
		X& operator=(const X&) { std::cout << "copy-assignment operator X& operator=(const X&)" << std::endl; return *this;}
		~X() { std::cout << "Destructor ~X()" << std::endl; }
};

void non_reference(X)
{
		std::cout << "In non_reference" << std::endl;
}

void reference(X&)
{
		std::cout << "In reference" << std::endl;
}

int main()
{
		X tmp_X;
		std::cout << "in main" << std::endl;
		non_reference(tmp_X);
		std::cout << "in main" << std::endl;
		reference(tmp_X);
		std::cout << "in main" << std::endl;
		std::cout << "\n\ngoing to dynamic allocate one" << std::endl;
		X *tmp_X2 = new X();
		std::vector<X> vec_x;
		std::cout << "vector push back X" << std::endl;
		vec_x.push_back(tmp_X);
		
		return 0;
}
