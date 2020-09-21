#ifndef QUERYR
#define QUERYR
#include <iostream>
#include <set>
#include <string>
#include <vector>

class QueryResult
{
private:
    friend class TextFile;
    friend class AndQuery;
    friend class OrQuery;
    friend class NotQuery;
    friend std::ostream &operator<<(std::ostream &os, const QueryResult &);
    std::string word;
    const std::vector<std::string> &text_ref;
    std::set<size_t> *set_ptr; //make shared
    QueryResult(const std::string &_w, const std::vector<std::string> &_text_ref, std::set<size_t> *_set_ptr) noexcept;

    class Iterator
    {
    private:
        using SetIterator = std::set<size_t>::iterator;
        SetIterator set_iterator;

    public:
        Iterator() = default;
        Iterator(const SetIterator &it);
        const size_t &operator*();
        bool operator!=(const Iterator &);
        Iterator &operator++();
    };

public:
    Iterator begin();
    Iterator end();
    ~QueryResult(); // set_ptr is deleted only if it was constructed by ~, |, &
};

#endif