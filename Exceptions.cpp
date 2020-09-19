#include "Exceptions.hpp"
#include <cstring>

NullPointerException::NullPointerException(const std::string &_msg) : msg(_msg) {}
NullPointerException::NullPointerException(const char *_msg) : msg() {}
const char *NullPointerException::what() const { return msg.c_str(); }

SetNullPointerException::SetNullPointerException() {}
SetNullPointerException::SetNullPointerException(const std::string &_msg) : NullPointerException(_msg) {}
const char *SetNullPointerException::what() const
{
    char *cstr = "set";
    return strcat(cstr, NullPointerException::what());
}