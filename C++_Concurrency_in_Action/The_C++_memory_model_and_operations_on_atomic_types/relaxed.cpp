#include <iostream>
#include <atomic>
#include <thread>
#include <assert.h>

std::atomic<bool> x, y;
std::atomic<int> z;

void write_x_then_y()
{
		x.store(true, std::memory_order_relaxed);
		y.store(true, std::memory_order_relaxed);
}

void read_y_then_x()
{
		while (!y.load(std::memory_order_relaxed));
		if (x.load(std::memory_order_relaxed))
				++z;
}

int main()
{
		x = false;
		y = false;
		z = 0;
		std::thread a(write_x_then_y);
		std::thread b(read_y_then_x);
		a.join();
		b.join();
		assert(z.load() != 0);
		/* assert can fire, because the load of x can read false, even thoough the load of y reads true and the store of x
		 * happens-before the store of y. x and y are different variables, so there are no ordering guarantees relating to this visibility
		 * of values arising from operations on each
		 */
		std::cout << "return from main" << std::endl;
}
