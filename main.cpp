#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "TextFile.hpp"
#include <fstream>

TEST_CASE("TextFile constructor")
{
    std::ifstream file("text.txt");
    TextFile text(file);
    std::cout << text << '\n';
}

int main()
{
    doctest::Context().run();
    return 0;
}