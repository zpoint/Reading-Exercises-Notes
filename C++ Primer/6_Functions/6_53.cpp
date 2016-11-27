#include <iostream>

int calc(int &i, int &j)
{
		std::cout << "In int calc(int&, int&): " << i << " " << j << std::endl;
		return i;
}

int calc(const int &i, const int &j)
{
		std::cout << "In calc(const int&, const int&): " << i << " " << j << std::endl;
		return 0;
}

int calc(char *a, char *b)
{
		std::cout << "In calc(char *， char *): " << *a << " " << *b << std::endl;
		return 0;
}

int calc(const char *a, const char *b)
{
		std::cout << "In calc(const char *, const char *): " << *a << " " << *b << std::endl;
		return 0;
}

int calcc(char *a, char *b)
{
		std::cout << "In calcc(char*, char *): " << *a << " " << *b << std::endl;
		return 0;
}

int calccc(char *const a, char *const b)
{
		std::cout << "In calccc(char *const, char *const): " << *a << " " << *b << std::endl;
		return 0;
}

int main()
{
		const int i = 1, j = 2;
		int k = 3, h = 4;
		calc(i, j);
		calc(k, h);
		calc(i, k);
		char a = 'a', b = 'b';
		const char c = 'c', d = 'd';
		calc(&a, &b);
		calc(&c, &d);
		calc(&c, &b);
		return 0;
}
