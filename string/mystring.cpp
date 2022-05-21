#include "mystring.h"

#include <iostream>
#include <cstring>

using namespace std;


namespace My
{

String::String()
    : _ptr(nullptr)
    , _size(0)
    , _copasity(0)
{
    std::cout << "String::String()" << std::endl;
}

String::String(const char* str)
    : _ptr(nullptr)
    , _size(0)
    , _copasity(0)
{
    std::cout << "String::String(const char* str)" << std::endl;
    if (str == nullptr)
        return;

    _size = strlen(str);
    _copasity = _size * 2;
    _ptr = new char[_copasity + 1]{};

    strncpy(_ptr, str, _copasity);
}

String::String(const String& other)
    : _ptr(nullptr)
    , _size(other._size)
    , _copasity(other._copasity)
{
    std::cout << "String::String(const String& other)" << std::endl;
    if (other._ptr)
    {
        _ptr = new char[_copasity + 1]{};
        strncpy(_ptr, other._ptr, _copasity);
    }
}

String::String(String&& other)
    : _ptr(other._ptr)
    , _size(other._size)
    , _copasity(other._copasity)
{
    std::cout << "String::String(String&& other)" << std::endl;

    other._ptr = nullptr;
    other._size = 0;
    other._copasity = 0;
}

String::~String()
{
    std::cout << "String::~String()" << std::endl;
    delete [] _ptr;
}

const char* String::c_str()
{
    return _ptr;
}

int64_t String::size()
{
    return _size;
}

String& String::append(const String& other)
{
    std::cout << "String::append(const String& other)" << std::endl;
    if (!other._ptr)
        return *this;

    if (_copasity < (other._size + _size))
    {
        _copasity = (other._size + _size) * 2;
        char* tmp = new char[_copasity + 1]{};

        strncpy(tmp, _ptr, _copasity);

        delete [] _ptr;
        _ptr = tmp;
    }

    strncat(_ptr, other._ptr, _copasity - _size);
    _size += other._size;

    return *this;
}

String& String::append(String&& other)
{
    std::cout << "String::append(String&& other)" << std::endl;

    append(other);
    other._ptr = nullptr;
    other._size = 0;
    other._copasity = 0;

    return *this;
}


} // My

/*
class MyString
{
public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);
    MyString(MyString&& other);

    ~MyString();

    char* c_str();
    int64_t size();
    MyString& append(const MyString& other);

private:
    char*   _ptr;
    int64_t _size;
    int64_t _copasity;
};
*/
