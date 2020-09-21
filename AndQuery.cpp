#include "AndQuery.hpp"
#include "QueryResult.hpp"

AndQuery::AndQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs) {}
std::string AndQuery::to_string() const noexcept
{
    return left.to_string() + " & " + right.to_string();
}
QueryResult AndQuery::eval(TextFile &file) const
{
    QueryResult eval_left = left.eval(file);
    QueryResult eval_right = right.eval(file);
    std::set<size_t> *res_set = new std::set<size_t>();

    for (auto el_left : eval_left)
    {
        for (auto el_right : eval_right)
        {
            if (el_left == el_right)
                res_set->insert(el_left);
        }
    }

    return QueryResult(to_string(), file.getText(), res_set);
}