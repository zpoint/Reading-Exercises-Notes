#include "TextQuery.h"

class Query;
class Query_base
{
		friend Query;
		protected:
			virtual ~Query_base() = default;
		private:
			virtual QueryResult eval(const TextQuery&) const = 0;
			virtual std::string rep() const = 0;
};

class Query
{
		friend Query operator~(const Query &);
		friend Query operator|(const Query&, const Query&);
		friend Query operator&(const Query&, const Query&);
		public:
			Query(const std::string&);
			QueryResult eval(const TextQuery &t) const { return q->eval(t); }
			std::string rep() const { return q->rep(); }
		private:
			Query(std::shared_ptr<Query_base> query): q(query) { }
			std::shared_ptr<Query_base> q;
};

class WordQuery: public Query_base
{
		friend class Query;
		WordQuery(const std::string &s): query_word(s) { std::cout << "WordQuery constructor: " << s << std::endl; }
		QueryResult eval(const TextQuery &t) const { return t.query(query_word); }
		std::string rep() const { return query_word; }
		std::string query_word;
};

inline Query::Query(const std::string &s): q(new WordQuery(s)) { std::cout << "Query constructor: " << s << std::endl; }

class NotQuery: public Query_base
{
		friend Query operator~(const Query &);
		NotQuery(const Query &q): query(q) { std::cout << "Not Query constructor" << rep() << std::endl; }
		std::string rep() const { return "~(" + query.rep() + ")"; }
		QueryResult eval(const TextQuery&) const { return QueryResult(); };
		Query query;
};

inline Query operator~(const Query &operand)
{
		return std::shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery: public Query_base
{
		protected:
			BinaryQuery(const Query &l, const Query &r, std::string s): lhs(l), rhs(r), opSym(s) { std::cout << "BinaryQuery constructor " << rep() << std::endl; }
			std::string rep() const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
			Query lhs, rhs;
			std::string opSym;
};

class AndQuery: public BinaryQuery
{
		friend Query operator& (const Query&, const Query&);
		AndQuery(const Query &left, const Query &right): BinaryQuery(left, right, "&") { std::cout << "AndQuery constructor " << rep() << std::endl;}
		QueryResult eval(const TextQuery&) const { return QueryResult(); }  // need implement, or compiler will complain
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
		return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery: public BinaryQuery
{
		friend Query operator| (const Query&, const Query&);
		OrQuery(const Query &left, const Query &right): BinaryQuery(left, right, "|") { std::cout << "OrQuery constructor " << rep() << std::endl; }
		QueryResult eval(const TextQuery&) const { return QueryResult();}
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
		return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}


int main()
{
		// BinaryQuery a = Query("fiery") & Query("bird"); // illegal, BinaryQuery is an abstract class
		// AndQuery b = Query("fiery") & Query("bird"); // no viable conversion from 'Query' to 'AndQuery'
		// OrQuery c = Query("fiery") & Query("bird"); // same
		return 0;
}
