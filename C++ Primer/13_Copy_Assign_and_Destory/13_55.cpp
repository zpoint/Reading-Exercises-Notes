#include<iostream>  
#include<vector>  
#include<string>  
#include<memory>  
#include<stdexcept>  
using namespace std;  
class StrBlob  
{  
		public:  
				typedef vector<string>::size_type size_type;  
				StrBlob():data(make_shared<vector<string>>()){}  
				StrBlob(initializer_list<string>il):data(make_shared<vector<string>>(il)){}  		  
				StrBlob(const StrBlob& sb):data(make_shared<vector<string>>(*sb.data)){}
				StrBlob& operator=(const StrBlob& sb)
				{ 
						data=make_shared<vector<string>>(*sb.data); 
						return *this;  
				}  
				size_type size()const{return data->size();}  
				bool empty(){return data->empty();}  
				void push_back(const string& str) & {data->push_back(str);}  
				// add here
				void push_back(const string& str) && {data->push_back(str); }
				void pop_back()
				{  
						check(0,"pop_back on empty StrBlob");  
						data->pop_back();  
				}  
				string& front()const  
				{  
						check(0,"front on empty StrBlob");  
						return data->front();  
				}  
				string& back()const  
				{  
						check(0,"back on empty StrBlob");  
						return data->back();  
				}  
		private:  
				shared_ptr<vector<string>> data;  
				void check(size_type i,const string& msg) const 
				{  
						if(i>=data->size())  
								throw out_of_range(msg);  
				}  
};  
