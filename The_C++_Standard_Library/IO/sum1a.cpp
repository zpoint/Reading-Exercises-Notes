#include <iostream>
#include <istream>

namespace MyLib
{
		double readAndProcessSum(std::istream& strm)
		{
				double value, sum;

				// save current state of exception flags
				std::ios::iostate oldExceptions = strm.exceptions();

				// let failbit and badbit throw exceptions
				// - NOTE: failbit it also set at end-of-file
				strm.exceptions(std::ios::failbit | std::ios::badbit);

				try
				{
						// while stream is OK
						// - read value and add it to sum
						sum = 0;
						while (strm >> value)
								sum += value;
				}
				catch (...)
				{
						// if exception not caused by end-of-file
						// - restore old state of exception floags
						// - rethrow exception
						if (!strm.eof())
						{
								strm.exceptions(oldExceptions); // restore exception floags
								std::cout << "throw in not strm.eof()" << std::endl;
								throw; // rethrow
						}
				}

				// restore old state of exception floags
				strm.exceptions(oldExceptions);
				// return sum
				return sum;
		}
};
