#include "OrQuery.hpp"

OrQuery::OrQuery(const Query &l, const Query &r) : BinaryQuery(l, r) {}
std::string OrQuery::to_string() const noexcept
{
    return left.to_string() + " | " + right.to_string();
}
QueryResult OrQuery::eval(TextFile &text) const
{
    QueryResult lqr = left.eval(text);
    QueryResult rqr = right.eval(text);

    SharedPtr<std::set<size_t>> new_set(new std::set<size_t>());

    for (size_t el : lqr)
    {
        new_set->insert(el);
    }

    for (size_t el : rqr)
    {
        new_set->insert(el);
    }

    return QueryResult(to_string(), lqr.text_ref, new_set);
}