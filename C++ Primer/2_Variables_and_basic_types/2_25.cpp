#include <iostream>

int main()
{
		int *ip, i, &r = i;
		std::cout << "ip: " << ip << " i: " << i << " r " << r << std::endl;
		int j, *jp = 0;
		std::cout << "j: " << j << " jp: " << jp << std::endl;
	    int *kp, kp2;	   
		std::cout << "kp: " << kp << " kp2: " << kp2 << std::endl;
	   return(0);
}	   
