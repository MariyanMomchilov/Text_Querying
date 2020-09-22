#ifndef QUERY
#define QUERY
#include "TextFile.hpp"
// ADD ITERATOR LATER

class Base_query;

class Query
{
private:
    SharedPtr<Base_query> to_query; // make shared
    Query(const SharedPtr<Base_query> &_ptr);

public:
    Query(const std::string &word = "");
    std::string to_string() const noexcept;
    QueryResult eval(TextFile &file) const;
    Query operator|(const Query &rhs);
    Query operator&(const Query &rhs);
    Query operator~();

    ~Query() = default;
};

#endif