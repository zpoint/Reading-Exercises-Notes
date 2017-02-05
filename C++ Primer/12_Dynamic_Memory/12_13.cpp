#include <memory>
#include <iostream>

int main()
{
		auto sp = std::make_shared<int>();
		auto p = sp.get();
		delete p; // cause core dump
		return 0;
}
