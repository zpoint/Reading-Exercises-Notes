#include <unordered_map>
#include <string>
#include <iostream>

int main()
{
		// type of the container:
		// - unordered_map: elements are key/value pairs
		// string: keys have type string
		// -float: values have type float
		std::unordered_map<std::string,float> coll;

		// insert some elements into the collection
		// - using the syntax of associative array
		coll["VAT1"] = 0.16;
		coll["VAT2"] = 0.07;
		coll["Pi"] = 3.1415;
		coll["an arbitary number"] = 4983.22;
		coll["Null"] = 0;

		// change value
		coll["VAT1"] += 0.03;

		// print differece of VAT values
		std::cout << "VAT difference: " << coll["VAT1"] - coll["VAT2"] << std::endl;
	   return 0;	
}
