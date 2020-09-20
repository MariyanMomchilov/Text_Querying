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
    friend std::ostream &operator<<(std::ostream &os, const QueryResult &);
    std::string word;
    std::vector<std::string> &text_ref;
    std::set<size_t> *set_ptr;
    QueryResult(const std::string &_w, std::vector<std::string> &_text_ref, std::set<size_t> *_set_ptr) noexcept;

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
    ~QueryResult() = default; // set_ptr is handled only by TextQuery for now
};

#endif