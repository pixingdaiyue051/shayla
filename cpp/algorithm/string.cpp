#include <cstring>
#include "string.h"

int String::_objNum = 0; // 初始化静态变量

String::String() {
    _len = 1;
    _str = new char[1];
    _objNum++;
    _str[0] = '\0'; // _str = 0; _str = (char *) 0; _str = NULL; _str = nullptr;
    std::cout << "obj[" << _str << "] created, [" << _objNum << "] remained" << std::endl;
}

String::String(const char *str) {
    _len = strlen(str);
    _str = new char[_len + 1];
    _objNum++;
    strcpy(_str, str);
    std::cout << "obj[" << _str << "] created, [" << _objNum << "] remained" << std::endl;
}

String::String(const String &s) {
    _len = s._len;
    _str = new char[_len + 1];
    _objNum++;
    strcpy(_str, s._str);
    std::cout << "obj[" << _str << "] created, [" << _objNum << "] remained" << std::endl;
}

String::~String() {
    _objNum--;
    std::cout << "obj[" << _str << "] deleted, [" << _objNum << "] remained" << std::endl;
    delete[] _str;
}

String &String::operator=(const String &s) {
    if (this == &s) {
        return *this;
    }
    _len = s._len;
    _str = new char[_len + 1];
    strcpy(_str, s._str);
    return *this;
}

String &String::operator=(const char *str) {
    delete[] _str;
    _len = strlen(str);
    _str = new char[_len + 1];
    strcpy(_str, str);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const String &s) {
    os << s._str;
    return os;
}

std::istream &operator>>(std::istream &is, String &s) {
    char tmp[String::CIN_MAX];
    is.get(tmp, String::CIN_MAX);
    if (is) {
        s = tmp;
    }
    while (is && is.get() != '\n');
    return is;
}

int String::getObjNum() {
    return _objNum;
}