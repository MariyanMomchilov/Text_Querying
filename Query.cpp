#include "Query.hpp"
#include "WordQuery.hpp"
#include "AndQuery.hpp"
#include "QueryResult.hpp"
//#include "OrQuery.hpp"
//#include "NotQuery.hpp"

Query::Query(const SharedPtr<Base_query> &_ptr) : to_query(_ptr) {}
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
    return Query(SharedPtr<Base_query>(new AndQuery(*this, rhs)));
}
