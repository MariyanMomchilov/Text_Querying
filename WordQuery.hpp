#ifndef WORD
#define WORD
#include "Base_query.hpp"

class WordQuery : public Base_query
{
private:
    friend class Query;
    std::string word;
    WordQuery(const std::string &_w = "");
    std::string to_string() const noexcept override;
    QueryResult eval(TextFile &file) const override;
};

#endif