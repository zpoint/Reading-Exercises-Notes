#include <vector>
#include <iostream>
#include <memory>

template <typename T> class Blob
{
		public:
			typedef T value_type;
			typedef typename std::vector<T>::size_type size_type;
			Blob();
			Blob(std::initializer_list<T> il);
			size_type size() const { return data->size(); }
			bool empty() const { return data->empty(); }
			void push_back(const T &t) { data->push_back(t); }
			void push_back(T &&t) { data->push_back(std::move(t)); }
			void pop_back();
			T& back();
			T& operator[](size_type i);
		private:
			std::shared_ptr<std::vector<T>> data;
			void check(size_type i, const std::string &msg) const;

};

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
		if (i >= data->size())
				throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::back()
{
		check(0, "back on empty Blob");
		return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
		check(i, "subscript out of range");
		return (*data)[i];
}

template <typename T> void Blob<T>::pop_back()
{
		check(0, "pop_back on empty Blob");
		data->pop_back();
}

template <typename T> Blob<T>::Blob() try : 
		data(std::make_shared<std::vector<T>>()) { }
		catch (const std::bad_alloc &e) { std::cout << "Bad alloc: " << e.what() << std::endl; }

template <typename T> Blob<T>::Blob(std::initializer_list<T> il) try: 
		data(std::make_shared<std::vector<T>>(il)) { }
		catch (const std::bad_alloc &e) { std::cout << "Bad alloc: " << e.what() << std::endl; }


template <typename T> class BlobPtr
{
		public:
			BlobPtr() try : curr(0) { }
			catch (...)
			{
					std::cout << "All excaption" << std::endl;
			}
			BlobPtr(Blob<T> &a, size_t sz = 0) try :
				   	wptr(a.data), curr(sz) { }
			catch (std::bad_alloc b)
			{
					std::cout << b.what() << std::endl;
			}
			T& operator*() const 
			{
					auto p = check(curr, "dereference past end");
					return (*p)[curr];
			}

			BlobPtr& operator++();
			BlobPtr operator++(int);
			BlobPtr& operator--();
		private:
			std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
			std::weak_ptr<std::vector<T>> wptr;
			std::size_t curr;
};

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
		BlobPtr ret = *this;
		++*this;
		return ret;
}

int main()
{
		Blob<int> ib;
		return 0;
}
