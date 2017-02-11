#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <map>
#include <set>
#include <vector>
#define BREAK_LINE "\r\n"
class QueryResult;

class TextQuery
{
		public:
				TextQuery(std::ifstream&);
				QueryResult query(std::string);
		private:
				std::vector<std::string> str_vec;
				std::shared_ptr<std::map<std::string, std::size_t>> line_map;
};

class QueryResult
{
		public:
				void print(std::ostream &cout)
				{
						if ((*line_map).size())
						{
								for (const auto &pair : (*line_map))
										cout << "(line " << pair.second << ") " << pair.first << BREAK_LINE;
						}
						else
								cout << "No result !!!" << BREAK_LINE;
				}
				QueryResult(std::shared_ptr<std::map<std::string, std::size_t>> arg_line_map): line_map(arg_line_map) { }
		private:
				std::shared_ptr<std::map<std::string, std::size_t>> line_map;
};

TextQuery::TextQuery(std::ifstream &infile)
{
		std::string buffer;
		while (infile >> buffer)
				str_vec.push_back(buffer);
}

QueryResult TextQuery::query(const std::string query)
{
		line_map = std::make_shared<std::map<std::string, std::size_t>>();
		std::size_t size_of_lines = str_vec.size(), query_size = query.size();
		for (std::size_t index = 0; index < size_of_lines; ++index)
		{
				std::string buffer = str_vec[index];
				std::size_t pos = std::string::npos, freq = 0;
				// find frequency
				do
				{
						std::cout << buffer << BREAK_LINE;
						pos = buffer.find_first_of(query);
						if (pos != std::string::npos)
						{
								buffer = buffer.substr(pos + query_size);
								++freq;
						}
				}
				while (pos != std::string::npos);
				if (freq)
						(*line_map)[buffer] = freq;
		}
		return QueryResult(line_map);
}


