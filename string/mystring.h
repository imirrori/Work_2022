#ifndef MYSTRING_H
#define MYSTRING_H

#include <cinttypes>

namespace My
{

class String
{
public:
    String();
    String(const char* str);
    String(const String& other);
    String(String&& other);

    ~String();

    const char* c_str();
    int64_t size();

    String& append(const String& other);
    String& append(String&& other);

private:
    struct DynamicString
    {
        char*   _ptr;
        int64_t _size;
        int64_t _copasity;
    };

    struct StaticString
    {
        char _data[12];
    };

    union {
        DynamicString _dynamic;
        StaticString _staic;
    };

    bool _is_dynamic;
};

} // My

#endif // MYSTRING_H
