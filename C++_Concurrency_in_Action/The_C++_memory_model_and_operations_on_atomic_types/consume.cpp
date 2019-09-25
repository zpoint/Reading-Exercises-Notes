#include <thread>
#include <atomic>
#include <string>

struct X
{
		int i;
		std::string s;
};

std::atomic<X*> p;
std::atomic<int> a;

void create_X()
{
		X* x = new X;
		x->i = 42;
		x->s = "hello";
		a.store(99, std::memory_order_relaxed);
		p.store(x, std::memory_order_release);

}

void use_X()
{
		X *x;
		while (!(x=p.load(std::memory_order_consume)))
				std::this_thread::sleep_for(std::chrono::microseconds(1));
		assert(x->i==42);
		assert(x->s=="hello");
		assert(a.load(std::memory_order_relaxed)==99);
}

int main()
{
		std::thread t1(create_X);
		std::thread t2(use_X);
		t1.join();
		t2.join();
		return 0;
		/*
		 * store to p only happens-before those expressions that are dependent on the value loaded from p.
		 * This means that the asserts on the data members of the X structure are guaranteed not to fire
		 */

}
