#include <iostream>

template <typename T> class shared_ptr
{
		public:
			shared_ptr(T *p, void (*del_func)(T*) = nullptr): ptr(p), destructor(del_func) { std::cout << "constructor " << std::endl; }
			~shared_ptr() 
			{
					std::cout << "destructor" << std::endl;	
					if (destructor)
							destructor(ptr);
					else
							delete ptr;
			}
		private:
			T *ptr;
			void (*destructor)(T*);
};


void destructor_int(int *ptr)
{
		std::cout << "User define ptr" << std::endl;
		delete ptr;
}


template <typename T, typename F> class unique_ptr
{
		public:
			unique_ptr(T *p, F *f): ptr(p), fun(f) { }
			~unique_ptr()
			{
					std::cout << "destructor" << std::endl;
					fun(ptr);
			}
		private:
			T *ptr;
			F *fun;
};

int main()
{
		shared_ptr<int> sp(new int(3), destructor_int);
		unique_ptr<int, void (int *)> u(new int(3), destructor_int);
		return 0;
}
