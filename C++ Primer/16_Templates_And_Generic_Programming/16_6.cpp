#include <iostream>

/*
 * overload template
 */

template <typename T>
auto begin(const T &container) -> decltype(container.begin())
{
		return container.begin();
}


template <typename T, unsigned N>
T *begin(T (&arr)[N])
{
		T *b = arr;
		return b;
}

template <typename T>
auto end(const T &container) -> decltype(container->end())
{
		return container.end();
}

template <typename T, unsigned N>
T *end(T(&arr)[N])
{
		T *e = &arr[N];
		return e + 1;
}

int main()
{
		std::cout << sizeof(double) << std::endl;
		double iarr[] = {13.0, 20.0};
		std::cout << begin(iarr) << std::endl;
		std::cout << end(iarr) << std::endl;
		std::string s("fdfdsfds");
		std::cout << *begin(s) << std::endl;
		std::cout << *end(s) << std::endl;
		return 0;
}
