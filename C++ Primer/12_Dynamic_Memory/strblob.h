#include <vector>
#include <string>
#include <memory>
#include <iostream>

class StrBlob
{
		public:
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
		private:
				std::shared_ptr<std::vector<std::string>> data;
				void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()) { }
StrBlob::StrBlob(std::initializer_list<std::string> il): data(std::make_shared<std::vector<std::string>>(il)) { }

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
