#ifndef AND
#define AND
#include "BinaryQuery.hpp"

class AndQuery : public BinaryQuery
{
private:
    friend class Query;
    AndQuery(const Query &lhs, const Query &rhs);
    std::string to_string() const noexcept override;
    QueryResult eval(TextFile &file) const override;
};

#endif