#include "Exceptions.hpp"
#include <cstring>

NullPointerException::NullPointerException(const std::string &_msg) noexcept : msg(_msg) {}
NullPointerException::NullPointerException(const char *_msg) noexcept : msg(_msg) {}
const char *NullPointerException::what() const noexcept { return msg.c_str(); }

std::string SetNullPointerException::name = "Set ";

SetNullPointerException::SetNullPointerException() noexcept : NullPointerException() { msg = name + msg; }
SetNullPointerException::SetNullPointerException(const std::string &_msg) noexcept : NullPointerException(_msg) { msg = name + msg; }
const char *SetNullPointerException::what() const noexcept
{
    return msg.c_str();
}