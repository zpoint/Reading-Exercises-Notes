#include <iostream>
#include <vector>
#include <string>
using std::string; using std::vector;
int main()
{
	double grade;
	string gradestr;
	vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
	std::cout << "Enter a grade (0 - 100), non numeric number or number not in range(0, 101) to terminate: " << std::endl;
	while (std::cin >> grade)
	{
		if (grade < 0 || grade > 100)
			break;

		gradestr = grade < 60 ? scores[0] : scores[static_cast<int>((grade - 50) / 10)];
		gradestr += grade == 100 || grade < 60 ? ""
			: static_cast<int>(grade) % 10 <= 3 ? "-"
			: static_cast<int>(grade) % 10 >= 7 ? "+"
			: "";
		std::cout << "grade: " << grade << " is " << gradestr << std::endl;
	}
	std::cout << "Terminate!" << std::endl;
	return(0);
}