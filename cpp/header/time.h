#ifndef SHAYLA_TIME_H
#define SHAYLA_TIME_H

#include <iostream>

class Time {
private:
    int _hour;
    int _minute;
public:
    Time();

    Time(int hour, int minute);

    void addHour(int hour);

    void addMinute(int minute);

    void reset(int hour = 0, int minute = 0);

    void show() const {
        std::cout << "hour:" << _hour << ",minute:" << _minute << std::endl;
    }

    Time operator+(const Time &time) const;

    Time operator*(int plus) const;

    friend Time operator*(int plus, const Time &time) {
        return time * plus;
    } // 非成员函数 友元函数可以访问私有变量

    friend std::ostream &operator<<(std::ostream &os, const Time &time) {
        os << "hour:" << time._hour << ",minute:" << time._minute;
        return os;
    } // 重载<<输出类信息 常用
};

#endif
