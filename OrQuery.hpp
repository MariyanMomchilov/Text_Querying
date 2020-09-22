#ifndef ORQUERY
#define ORQUERY
#include "BinaryQuery.hpp"
#include "QueryResult.hpp"

class OrQuery : public BinaryQuery
{
private:
    friend class Query;
    OrQuery(const Query &l, const Query &r);
    std::string to_string() const noexcept override;
    QueryResult eval(TextFile &) const override;
};

#endif