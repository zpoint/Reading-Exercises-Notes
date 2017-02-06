#include <vector>
#include <string>
#include <memory>
#include <iostream>
class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob
{
		public:
				friend class StrBlobPtr;
				friend class ConstStrBlobPtr;
				typedef std::vector<std::string>::size_type size_type;
				StrBlob();
				StrBlob(std::initializer_list<std::string> il);
				size_type size() const { return data->size(); }
				bool empty() const { return data->empty(); }
				void push_back(const std::string &t) const { data->push_back(t); }
				void pop_back() const;
				size_type use_count() const;
				void pr_data(std::string) const;
				std::string& front() const;
				std::string& back() const;
				StrBlobPtr begin();
				ConstStrBlobPtr cbegin() const;
				StrBlobPtr end();
				ConstStrBlobPtr cend() const;
		private:
				std::shared_ptr<std::vector<std::string>> data;
				void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr
{
		public:
				StrBlobPtr(): curr(0) { }
				StrBlobPtr(StrBlob &a, std::size_t sz = 0): wptr(a.data), curr(sz) { }
				std::string& deref() const;
				StrBlobPtr& incr();
		private:
				std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
				std::weak_ptr<std::vector<std::string>> wptr;
				std::size_t curr;
};

class ConstStrBlobPtr
{
		private:
				std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string& msg) const
				{
						auto ret = wptr.lock();
						if (!ret)
								throw std::runtime_error("unbound StrBlobPtr");
						if (i >= ret->size())
								throw std::out_of_range(msg);
						return ret; // otherwise, return a shared_ptr to the vector
				}
				std::weak_ptr<std::vector<std::string>> wptr;
				std::size_t curr;

		public:
				ConstStrBlobPtr(): curr(0) { }
				ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0): wptr(a.data), curr(sz) { }
				
				std::string& deref() const { auto p = check(curr, "defrerence past end"); return (*p)[curr]; }
				ConstStrBlobPtr& incr() { check(curr, "Increment past end of ConstStrBlobPtr"); ++curr; return *this; }
};

StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()) { }
StrBlob::StrBlob(std::initializer_list<std::string> il): data(std::make_shared<std::vector<std::string>>(il)) { }
StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { auto ret = StrBlobPtr(*this, data->size()); return ret; } 
ConstStrBlobPtr StrBlob::cbegin() const { return ConstStrBlobPtr(*this); }
ConstStrBlobPtr StrBlob::cend() const { auto ret = ConstStrBlobPtr(*this, data->size()); return ret; }

void StrBlob::pop_back() const
{
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
}

StrBlob::size_type StrBlob::use_count() const
{
		return data.use_count();
}

void StrBlob::pr_data(const std::string name="") const
{
		std::cout << name << " use count is: " << data.use_count() << std::endl;
		if (!data->size())
				std::cout << name << " is empty!!!\n" << std::endl;
		else
		{
				std::cout << name << " has " << data->size() << " elements " << std::endl;
				for (const auto &item : *data)
						std::cout << item << " ";
				std::cout << "\n" << std::endl;
		}
}


std::string& StrBlob::front() const
{
		check(0, "front on empty StrBlob");
		return data->front();
}
std::string& StrBlob::back() const
{
		check(0, "back on empty StrBlob");
		return data->back();
}

void StrBlob::check(size_type i, const std::string &msg) const
{
		if (i >= data->size())
				throw std::out_of_range(msg);
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
		auto ret = wptr.lock();
		if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
		if (i >= ret->size())
				throw std::out_of_range(msg);
		return ret; // otherwise, return a shared_ptr to the vector
}

std::string& StrBlobPtr::deref() const
{
		auto p = check(curr, "dereference past end");
		return (*p)[curr]; 
}

StrBlobPtr& StrBlobPtr::incr()
{
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
}
