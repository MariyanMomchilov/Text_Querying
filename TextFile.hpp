#ifndef TEXTFILE
#define TEXTFILE
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

class QueryResult;

class TextFile
{
private:
    static const char *delimiters;
    std::vector<std::string> text_lines;
    std::map<std::string, std::set<size_t> *> word_mapper;

    friend std::ostream &operator<<(std::ostream &os, const TextFile &);
    std::vector<std::string> separate_words(std::string &line);
    bool is_delimiter(char c) const;
    QueryResult query() const;

public:
    TextFile(std::istream &is);
    ~TextFile();
};

#endif