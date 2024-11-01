#ifndef SHAYLA_STRING_H
#define SHAYLA_STRING_H

#include <iostream>

class String {
private:
    char *_str;
    int _len;
    static int _objNum; // static由全部类成员共享 记录嘞成员数量
    static const int CIN_MAX = 128;
public:
    String();

    String(const char *str);

    String(const String &s); // 深度复制函数 当成员变量中有指针变量是最好提供该函数 避免潜在的传参错误

    ~String();

    String &operator=(const String &s);

    String &operator=(const char *str);

    friend std::ostream &operator<<(std::ostream &os, const String &s);

    friend std::istream &operator>>(std::istream &is, String &s);

    static int getObjNum(); // 静态成员函数 只能访问静态成员变量 需要通过类作用域访问

};

#endif