#include <iostream>
#include <memory>

int main()
{
		int ix = 1024, *pi = &ix, *pi2 = new int(2048);
		typedef std::unique_ptr<int> IntP;
		// IntP p0(ix); // error, constructor must take a new address boject
		// IntP p1(pi); // error, same as previous one
		IntP p2(pi2); // ok
		// IntP p3(&ix); // error
		IntP p4(new int(2048)); // ok
		IntP p5(p2.get()); // bad, delete twice when out of this scope
		return 0;
}
