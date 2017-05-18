#include <iostream>
#include <memory>
#include <string>

template <typename T, typename... Args>
std::shared_ptr<T> make_shared(Args&&... args)
{
		return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}

int main()
{
		std::shared_ptr<std::string> ptr = make_shared<std::string>(10, 's');
		std::cout << *ptr << std::endl;
		return 0;
}
