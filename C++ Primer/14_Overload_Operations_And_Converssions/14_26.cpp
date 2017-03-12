/*
 * just String class
 */
#include <iostream>
#include <memory>
#include <utility>

class String {
		public:
				friend bool operator==(const String &, const String &);
				friend bool operator>(const String &, const String &);
				friend std::ostream &operator<<(std::ostream &, const String &);
				String(): element(nullptr) { }
				String(const char *);
				String(const String&);
				String& operator=(const String&);
				char& operator[](const std::size_t);
				const char& operator[](const std::size_t) const;
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
		std::cout << "calling const char *ptr" << std::endl;
		size_t len = 0;
		const char *ini_ptr = ptr;
		while (*ptr++)
				len++;
		char *begin = alloc.allocate(len);
		element = begin;
		length = len;

		while (*ini_ptr)
				alloc.construct(begin++, *ini_ptr++);
		std::cout << "After construct: " << *this << std::endl;
}

String::String(const String &rhs)
{
		std::cout << "calling const Strikng &rhs" << std::endl;
		if (rhs.length > 0)
		{
				char *begin = alloc.allocate(rhs.length);
				char *ini_ptr = rhs.begin();
				element = begin;
				length = rhs.length;
				while (*ini_ptr)
						alloc.construct(begin++, *ini_ptr++);
		}
		std::cout << *this << std::endl;
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

bool operator==(const String &lhs, const String &rhs)
{
		if (lhs.length != rhs.length)
				return false;
		for (std::size_t index = 0; index < lhs.length; ++index)
		{
				if (*(lhs.element + index) != *(rhs.element + index))
						return false;
		}
		return true;
}

bool operator!=(const String &lhs, const String &rhs)
{
		return !(lhs==rhs);
}

bool operator>(const String &lhs, const String &rhs)
{
		if (lhs.length > rhs.length)
				return true;
		else if (lhs.length < rhs.length)
				return false;
		for (std::size_t index = 0; index < lhs.length; ++index)
		{
				if (*(lhs.begin() + index) > *(rhs.begin() + index))
						return true;
		}
		return false;
}

bool operator<(const String &lhs, const String &rhs)
{
		return !(lhs > rhs) && !(lhs == rhs);
}

std::ostream &operator<<(std::ostream &os, const String &str)
{
		for (auto c : str)
				os << c;
		return os;
}

char& String::operator[](const std::size_t index)
{
		if (index > length - 1)
				throw std::out_of_range("");
		return element[index];
}

const char& String::operator[](const std::size_t index) const
{
		if (index > length - 1)
				throw std::out_of_range("");
		return element[index];
}

int main()
{
		const char string[] = "abc";
		String str(string), str2(str);
		str[2] = 'a';
		std::cout << str2 << std::endl;
		std::cout << str << std::endl;
		std::cout << (str == str2) << std::endl;
		std::cout << (str != str2) << std::endl;
		std::cout << (str < str2) << std::endl;
		return 0;
}
