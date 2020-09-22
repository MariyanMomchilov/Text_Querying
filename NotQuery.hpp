#ifndef NOTQUERY
#define NOTQUERY
#include "Base_query.hpp"
#include "QueryResult.hpp"
#include "Query.hpp"

class NotQuery : public Base_query
{
protected:
    Query query;

private:
    friend class Query;
    NotQuery(const Query &q);
    std::string to_string() const noexcept override;
    QueryResult eval(TextFile &) const override;
};

#endif