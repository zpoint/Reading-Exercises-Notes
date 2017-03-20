
/*
 * class inheritance, derived class and base class
 */

class base
{

};

class derived : public base
{
};

int main()
{
		base *cls;
		derived d;
		cls = &d; // example
		return 0;
}
