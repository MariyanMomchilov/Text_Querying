#include "Query.hpp"
#include "WordQuery.hpp"
#include "AndQuery.hpp"
#include "QueryResult.hpp"
//#include "OrQuery.hpp"
//#include "NotQuery.hpp"

Query::Query(Base_query *_ptr) : to_query(_ptr) {}
Query::Query(const std::string &word) : to_query(new WordQuery(word)) {}
std::string Query::to_string() const noexcept
{
    return to_query->to_string();
}
QueryResult Query::eval(TextFile &file) const
{
    return to_query->eval(file);
}

Query Query::operator&(const Query &rhs)
{
    return Query(new AndQuery(*this, rhs));
}

Query::~Query()
{
    if (to_query != nullptr)
        delete to_query;
}