#include <vector>
#include <iostream>
#include <string>

void pr_status(const std::vector<std::string> &svec, const std::string str)
{
		if (str != "")
				std::cout << str << "\n";
		std::cout << "size: " << svec.size() << "\n" <<
				"capacity: " << svec.capacity() << "\n" << std::endl;
}

int main()
{
		std::vector<std::string> svec(10);
		pr_status(svec, "After creating svec");
		svec.reserve(1024);
		pr_status(svec, "After reserve(1024): ");
		std::string word;
		std::cout << "Input some string: " << std::endl;
		while (std::cin >> word)
				svec.push_back(word);
		pr_status(svec, "After push_back these input strnig");
		svec.resize(svec.size() + svec.size() / 2);
		pr_status(svec, "After resize(sive.size() + svec.size() / 2)");
		return 0;
}
