#include <iostream>
#include <string>

int main()
{
		int grade = 61;
		std::string FinalGrade;
		FinalGrade = (grade > 90) ? "high pass" 
								   : (grade > 75) ? "pass"
								   				  : (grade > 60) ? "low pass" : "fail";
		std::cout << FinalGrade << std::endl;

		if (grade > 90)
				FinalGrade = "high pass";
		else if (grade > 75)
				FinalGrade = "pass";
		else if (grade > 60)
				FinalGrade = "low pass";
		else
				FinalGrade = "fail";
		std::cout << FinalGrade << std::endl;
		// if else satement is beffer understanding
		return(0);
}
