#ifndef BIN
#define BIN
#include "Base_query.hpp"
#include "Query.hpp"

class BinaryQuery : public Base_query
{
private:
    friend class Query;
    std::string to_string() const noexcept override = 0;
    QueryResult eval(TextFile &file) const override = 0;

protected:
    Query left;
    Query right;
    BinaryQuery(const Query &lhs, const Query &rhs);
    virtual ~BinaryQuery() = default;
};

#endif