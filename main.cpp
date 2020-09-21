#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
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
    std::ifstream file("text.txt");
    TextFile text(file);
    std::cout << text << '\n';
    file.close();
}

TEST_CASE("ResultQuery")
{
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
    std::ifstream file("text.txt");
    TextFile text(file);

    std::cout << Query("Roses").eval(text) << '\n';
    //Query q1 = Query("Sugar");
    Query q1("Sugar");
    Query q2("sweet");
    Query andQ = q1 & q2;

    std::cout << andQ.eval(text) << '\n'
              << andQ.to_string() << '\n';
    file.close();
}

TEST_CASE("Queries")
{
    std::ifstream file("text.txt");
    TextFile text(file);

    std::cout << Query("Roses").eval(text) << '\n';
    Query andQ = Query("Sugar") & Query("sweet");

    std::cout << andQ.eval(text) << '\n'
              << andQ.to_string() << '\n';
    file.close();
}

int main()
{
    doctest::Context().run();
    return 0;
}