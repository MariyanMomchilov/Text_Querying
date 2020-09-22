#ifndef TEXTFILE
#define TEXTFILE
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include "SharedPtr.cpp"

class QueryResult;

class TextFile
{
private:
    static const char *delimiters;
    std::vector<std::string> text_lines;
    std::map<std::string, SharedPtr<std::set<size_t>>> word_mapper; // make set* shared

    friend std::ostream &operator<<(std::ostream &os, const TextFile &);
    std::vector<std::string> separate_words(std::string &line);
    bool is_delimiter(char c) const;

public:
    TextFile(std::istream &is);
    QueryResult query(const std::string &word);
    const std::vector<std::string> &getText() const;
    ~TextFile() = default;
};

#endif