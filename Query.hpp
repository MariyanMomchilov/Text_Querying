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
    Query();
    Query(Base_query *_ptr);
    ~Query();
};

#endif