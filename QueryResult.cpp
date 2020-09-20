#include "QueryResult.hpp"

QueryResult::QueryResult(const std::string &_w, std::vector<std::string> &_text_ref, std::set<size_t> *_set_ptr) noexcept : word(_w), text_ref(_text_ref), set_ptr(_set_ptr) {}

QueryResult::Iterator QueryResult::begin() { return Iterator(set_ptr->begin()); }
QueryResult::Iterator QueryResult::end() { return Iterator(set_ptr->end()); }

QueryResult::Iterator::Iterator(const SetIterator &it) : set_iterator(it) {}

const size_t &QueryResult::Iterator::operator*()
{
    return *set_iterator;
}

bool QueryResult::Iterator::operator!=(const Iterator &it)
{
    return set_iterator != it.set_iterator;
}
QueryResult::Iterator &QueryResult::Iterator::operator++()
{
    set_iterator++;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const QueryResult &qr)
{
    os << "Results for word: " << qr.word << '\n';
    for (size_t el : *qr.set_ptr)
    {
        os << el << ": " << qr.text_ref[el] << '\n';
    }
    return os;
}
