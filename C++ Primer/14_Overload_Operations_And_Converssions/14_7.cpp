#include <iostream>
#include <memory>
#include <utility>

class String {
		public:
				String(): element(nullptr) { }
				String(const char *);
				String(const String&);
				String& operator=(const String&);
				~String();
				
				char *begin() const { return element; }
				char *end() const { return element + length; }
		private:
				static std::allocator<char> alloc;
				char *element; // first element
				size_t length = 0;
};

std::allocator<char> String::alloc;

String::String(const char *ptr)
{
		size_t len = 0;
		const char *ini_ptr = ptr;
		while (*ptr++)
				len++;
		char *begin = alloc.allocate(len);
		element = begin;
		length = len;

		while (*ini_ptr)
				alloc.construct(begin++, *ini_ptr++);
}

String::String(const String& rhs)
{
		String(rhs.begin());
}

String& String::operator=(const String& rhs)
{
		String(rhs.begin());
		return *this;
}

String::~String()
{
		std::cout << "Bad destructor " << std::endl;
		for (size_t index = 0; index < length; ++index)
				alloc.destroy(element + index);
		std::cout << "destructor here? " << std::endl;
		alloc.deallocate(element, length);
}

std::ostream& operator<<(std::ostream &os, const String &str)
{
		for (const auto chara : str)
				os << chara;
		return os;
}

int main()
{
		const char string[] = "abc";
		String str(string), str2(str);
		std::cout << str << std::endl;
		return 0;
}
