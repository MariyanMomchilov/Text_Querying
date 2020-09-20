#ifndef QUERY
#define QUERY
#include "TextFile.hpp"
// ADD ITERATOR LATER

class Base_query;

class Query
{
private:
    Base_query *to_query;

public:
    Query(const std::string &word = "");
    std::string to_string() const;
    QueryResult eval(TextFile &file) const;
    Query(Base_query *_ptr);
    ~Query();
};

#endif