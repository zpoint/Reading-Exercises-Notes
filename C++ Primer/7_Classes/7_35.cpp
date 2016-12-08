#include <iostream>
#include <string>

using std::string;

typedef string Type;
Type initVal()
{
		return "Calling initVal";
}

class Exercise {
		public:
				typedef double Type;
				Type setVal(Type);
				Type initVal();
		private:
				int val;
};

Exercise::Type Exercise::setVal(Type parm)
{
		std::cout << "Calling setVal \n";
		std::cout << "Before set, val: " << val << "\n";
		val = static_cast<int>(parm);
		std::cout << "After set, val: " << val  << std::endl;
		return val;
}

int main()
{
		Exercise e;
		e.setVal(3.5);
		return 0;
}
