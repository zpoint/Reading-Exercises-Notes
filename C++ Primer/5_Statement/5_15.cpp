#include <iostream>

int main()
{
	// a
	int sz = 10;
	for (int ix = 0; ix != sz; ++ix){}
	// ix in scope for, outside for, ix can't be used

	// b
	int ix = 0; // ix should be initialized
	for (; ix != sz; ++ix){} // miss the first ;
	
	// c
	for (int ix = 0; ix != sz; ++ix /* ++sz */ ) {}
	/*
	 * if ix != sz in the first time, ix will never equal sz
	 * because ix && sz both increment 1 each time
	 */
	return(0);
}