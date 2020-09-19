#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "TextFile.hpp"
#include "QueryResult.hpp"
#include <fstream>

//#include "TextFile.cpp"
//#include "QueryResult.cpp"
//#include "Exceptions.cpp"

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

int main()
{
    doctest::Context().run();
    return 0;
}