#include <iostream>

class CAD
{
};

class Vehicle
{
};

class CADVehicle : public CAD, Vehicle
{
};

class DblList : public CAD, public Vehicle
{
};

class iostream : public std::istream, public std::ostream
{
};

int main()
{
		CADVehicle c;
		DblList d;
		iostream i;
		return 0;
}
