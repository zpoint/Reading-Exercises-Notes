#include <iostream>

template <typename T>
void f(T t)
{
		std::cout << "Calling void f(T): " << t << std::endl;
}

template <typename T>
void f(const T *ptr)
{
		std::cout << "Calling void f(const T*): " << ptr << std::endl;
}

template <typename T>
void g(T t)
{
		std::cout << "Calling void g(T): " << t << std::endl;
}

template <typename T>
void g(T *ptr)
{
		std::cout << "Calling void g(T*): " << ptr << std::endl;
}

int main()
{
		int i = 42, *p = &i;
	    const int ci = 0, *p2 = &ci;
		g(42);
		g(p);
		g(ci); // g(T)  T is const int
		g(p2); // g(T *) T is const int
		f(42);
		f(p);
		f(ci);  // f(T) const int
		f(p2); // f(const T *)
		return 0;
}
