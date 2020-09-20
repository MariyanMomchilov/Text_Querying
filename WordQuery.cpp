#include "WordQuery.hpp"
#include "QueryResult.hpp"

WordQuery::WordQuery(const std::string &_w = "") : Base_query(), word(_w) {}
std::string WordQuery::to_string() const noexcept
{
    return "Query for " + word;
}

QueryResult WordQuery::eval(TextFile &file) const
{
    return file.query(word);
}