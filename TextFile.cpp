#include "TextFile.hpp"

const char *TextFile::delimiters = ",.:;!? \t\n";

bool TextFile::is_delimiter(char c) const
{
    int i = 0;
    while (delimiters[i] != '\0')
    {
        if (delimiters[i++] == c)
            return true;
    }
    return false;
}

std::vector<std::string> TextFile::separate_words(std::string &line)
{
    std::vector<std::string> words;
    std::string current_word;

    for (char &el : line)
    {
        if (is_delimiter(el))
        {
            if (current_word != "")
            {
                words.push_back(current_word);
                current_word = "";
            }
        }
        else
            current_word.push_back(el);
    }
    if (current_word != "")
        words.push_back(current_word);

    return words;
}

TextFile::TextFile(std::istream &is)
{
    size_t current_line = 0;
    while (!is.eof())
    {
        std::string line;
        getline(is, line);
        text_lines.push_back(line);
        std::vector<std::string> words = separate_words(line);
        for (std::string &word : words)
        {
            word_mapper[word].insert(current_line);
        }
        current_line++;
    }
}

std::ostream &operator<<(std::ostream &os, const TextFile &text)
{
    os << "Text: ";
    for (auto line : text.text_lines)
        os << line << '\n';

    os << "\nwords -> lines: \n";
    for (auto pair : text.word_mapper)
    {
        os << pair.first << "-> ";
        for (size_t el : pair.second)
            os << el << ", ";
        os << '\n';
    }
    return os;
}