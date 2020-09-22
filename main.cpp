#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "SharedPtr.cpp"
#include "TextFile.hpp"
#include "QueryResult.hpp"
#include "Query.hpp"
#include <fstream>

/*#include "TextFile.cpp"
#include "QueryResult.cpp"
#include "Exceptions.cpp"
#include "WordQuery.cpp"
#include "Query.cpp"
#include "AndQuery.cpp"
#include "BinaryQuery.cpp"*/

TEST_CASE("TextFile constructor")
{
    std::cout << "TextFile case\n\n";
    std::ifstream file("text.txt");
    TextFile text(file);
    std::cout << text << '\n';
    file.close();
}

TEST_CASE("ResultQuery")
{
    std::cout << "ResultQuery case\n\n";
    std::ifstream file("text.txt");
    TextFile text(file);
    QueryResult result = text.query("are");
    try
    {
        QueryResult kiro = text.query("kiro");
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << result << '\n';
    file.close();
}

TEST_CASE("Queries")
{
    std::cout << "Queries case\n\n";
    std::ifstream file("text.txt");
    TextFile text(file);

    std::cout << Query("Roses").eval(text) << '\n';
    //Query q1 = Query("Sugar");
    Query q1("Sugar");
    Query q2("sweet");
    Query andQ = q1 & q2;

    std::cout << andQ.eval(text) << '\n'
              << andQ.to_string() << '\n';

    Query notq = ~andQ;

    std::cout << notq.eval(text) << '\n'
              << notq.to_string() << '\n';

    Query orq = q2 | Query("Violets");

    std::cout << orq.eval(text) << '\n'
              << orq.to_string() << '\n';

    std::cout << (orq | notq).eval(text) << '\n';

    file.close();
}

TEST_CASE("Shared pointer")
{
    std::cout << "Shared pointers case\n\n";

    SharedPtr<int> int_ptr(new int(3));
    SharedPtr<int> int_ptr2(int_ptr);

    CHECK(int_ptr.count_references() == 2);
    CHECK(int_ptr2.count_references() == 2);

    int_ptr2 = SharedPtr<int>(new int(5));
    CHECK(int_ptr.count_references() == 1);
    CHECK(int_ptr2.count_references() == 1);
}

int main()
{
    doctest::Context().run();
    return 0;
}