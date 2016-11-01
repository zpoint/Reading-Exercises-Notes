#include <iostream>

int main()
{
		// const int buf; should be initilized
		int cnt = 0;
		const int sz = cnt;
		++cnt; // ++sz; const can't change
		return(0);
}
