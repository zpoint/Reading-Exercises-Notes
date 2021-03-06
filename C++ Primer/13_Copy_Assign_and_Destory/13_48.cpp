#include <iostream>
#include <memory>
#include <utility>
#include <vector>

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
				void reallocate(const char *, size_t len);
				static std::allocator<char> alloc;
				char *element; // first element
				size_t length = 0;
};

std::allocator<char> String::alloc;

void String::reallocate(const char *ptr, size_t len)
{
		if (len <= 0)
				throw std::runtime_error("Bad call reallocate!!!");
		char *begin = alloc.allocate(len);
		element = begin;
		length = len;

		for (size_t index = 0; index < len; ++index, ++begin)
				alloc.construct(begin, *(ptr + index));

}


String::String(const char *ptr)
{
		size_t len = 0;
		const char *ini_ptr = ptr;
		while (*ptr++)
				len++;
		reallocate(ini_ptr, len);
}

String::String(const String& rhs)
{
		std::cout << "Copy constructor" << std::endl;
		reallocate(rhs.begin(), rhs.length);
}

String& String::operator=(const String& rhs)
{
		std::cout << "Copy assign constructor" << std::endl;
		reallocate(rhs.begin(), rhs.length);
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

int main()
{
		const char string[] = "abc";
		String str(string), str2(str), str3;
		str3 = str2;
		std::vector<String> Svec;
		std::cout << "Going to push back" << std::endl;
		Svec.push_back(str);
		std::cout << "After push back str" << std::endl;
		Svec.push_back(str2);
		std::cout << "After push back str2" << std::endl;
		Svec.push_back(str3);
		std::cout << "After push back str3" << std::endl;
		std::cout << "REturn from main" << std::endl;
		return 0;
}
