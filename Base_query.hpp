#ifndef BASE
#define BASE
#include "TextFile.hpp"

class Base_query
{
private:
    friend class Query;
    virtual std::string to_string() const noexcept = 0;
    virtual QueryResult eval(TextFile &file) const = 0;

public:
    virtual ~Base_query() = default;
};

#endif