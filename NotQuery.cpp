#include "NotQuery.hpp"

NotQuery::NotQuery(const Query &q) : Base_query(), query(q) {}
std::string NotQuery::to_string() const noexcept
{
    return "~" + query.to_string();
}
QueryResult NotQuery::eval(TextFile &text) const
{
    QueryResult qr = query.eval(text);
    SharedPtr<std::set<size_t>> new_set(new std::set<size_t>());
    for (int i = 0; i < qr.text_ref.size(); i++)
    {
        if (qr.set_ptr->find(i) == qr.set_ptr->end())
            new_set->insert(i);
    }
    return QueryResult(to_string(), qr.text_ref, new_set);
}