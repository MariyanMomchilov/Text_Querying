#ifndef EXCEPTIONS
#define EXCEPTIONS
#include <stdexcept>

class NullPointerException : public std::exception
{
protected:
    mutable std::string msg;

public:
    NullPointerException(const std::string &_msg) noexcept;
    NullPointerException(const char *_msg = "pointer to null!") noexcept;
    const char *what() const noexcept override;
};

class SetNullPointerException : public NullPointerException
{

    static std::string name;

public:
    SetNullPointerException() noexcept;
    SetNullPointerException(const std::string &_msg) noexcept;
    const char *what() const noexcept override;
};

#endif