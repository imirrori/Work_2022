#include <iostream>

#include "mystring.h"

using namespace std;

int main()
{
    My::String object_1("qweqw");
    std::cout << "object_1: " << object_1.c_str() << std::endl;

    object_1.append("123").append("456").append("789");
    std::cout << "object_1: " << object_1.c_str() << std::endl;
}
