#include <bitset>
#include <iostream>

int main()
{
		// enumeration type for the bits
		// - each bit represents a color
		enum Color { red, yellow, green, blue, white, black, numColors };

		// create bitset for all bits/color
		std::bitset<numColors> usedColors;

		// set bits for two colors
		usedColors.set(red);
		usedColors.set(blue);

		// print some bitset data
		std::cout << "bitfield of used colors:    " << usedColors << std::endl;
		std::cout << "number of used colors:      " << usedColors.count() << std::endl;
		std::cout << "bitfield of unused colors:  " << ~usedColors << std::endl;

		// if any color is used
		if (usedColors.any())
		{
				// loop over all colors
				for (int c = 0; c < numColors; ++c)
				{
						// if the actual color is used
						if (usedColors[(Color)c])
								std::cout << "used color: " << c << std::endl;
				}
		}

		return 0;
}
