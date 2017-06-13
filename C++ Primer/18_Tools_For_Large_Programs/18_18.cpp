#include <iostream>
#include <string>

class T
{
		public:
			T(int val): mem1(val) { }
			int mem1;
};

void swap(T &v1, T &v2)
{
		std::cout << "IN user defined swap" << std::endl;
		using std::swap;
		std::swap(v1.mem1, v2.mem1);
}

int main()
{
		T v1(1), v2(2);
		swap(v1, v2);
		std::cout << "v1: " << v1.mem1 << " v2: " << v2.mem1 << std::endl;
		return 0;
}
