#ifndef SHAYLA_TIME_H
#define SHAYLA_TIME_H

#include <iostream>

namespace TIME {

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


    class Stock {
    private:
        std::string _company;
        long _share;
        double _price;
        double _total;
//    enum { MAX = 100}; // 类内部定义个常量
//    static const int max = 100; // 类内部定义个静态常量 静态变量会被类所有成员共享
//    long val[MAX];
    public:
        Stock(); // 如果构造函数所有参数都有默认值 那默认构造函数可以省略

        explicit Stock(long share = 0, double price = 0.0, const std::string &company = "");

//    Stock(long share, double price, const std::string &company);

        ~Stock(); // 类被回收或销毁时自动调用 一般用于对使用new创建的内存做回收

        void setTotal() {
            _total = _price * _share;
        }

        void buy(long share, double price);

        void sell(long share, double price);

        void update(double price);

        void show();

        explicit operator double() const;

    };
}

#endif
