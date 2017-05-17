#include <iostream>
#include <string>
#include <utility>
#include <memory>
#include <vector>

template <typename T> class Vec {
		public:
			Vec(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
			Vec(const Vec&);
			Vec &operator=(const Vec&);
			~Vec();
			void push_back(const T&);
			size_t size() const { return first_free - elements; }
			size_t capacity() const { return first_free - elements; }
			T *begin() const { return elements; }
			T *end() const { return first_free; }
		private:
			static std::allocator<T> alloc;
			void chk_n_alloc() {if (size() == capacity()) reallocate(); }
			std::pair<T*, T*> alloc_n_copy(const T*, const T*);
			void free();
			void reallocate();
			T *elements;
			T *first_free;
			T *cap;
};

template <typename T>
Vec<T>::Vec(const Vec &s)
{
		auto new_data = alloc_n_copy(s.begin(), s.end());
		elements = new_data.first;
		first_free = cap = new_data.second;
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec &rhs)
{
		auto data = alloc_n_copy(rhs.begin(), rhs.end());
		free();
		elements = data.first;
		first_free = cap = data.second;
}

template <typename T>
Vec<T>::~Vec<T>()
{
		free();
}

template <typename T>
void Vec<T>::push_back(const T &s)
{
		chk_n_alloc();
		alloc.construct(first_free++, s);
}

template <typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
		auto data = alloc.allocate(e - b);
		return {data, std::uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free()
{
		if (elements)
		{
				for (auto p = first_free; p != elements; )
						alloc.destroy(--p);
				alloc.deallocate(elements, cap - elements);
		}
}

template <typename T>
void Vec<T>::reallocate()
{
		auto newcapacity = size() ? 2 * size() : 1;
		auto new_data = alloc.allocate(newcapacity);
		auto dest = new_data;
		auto elem = elements;
		for (size_t i = 0; i != size(); ++i)
				alloc.construct(dest++, std::move(*elem++));
		free();
		elements = new_data;
		first_free = dest;
		cap = elements + newcapacity;
}

template <typename T>
std::allocator<T> Vec<T>::alloc;

int main()
{
		Vec<int> svec;
		return 0;
}
