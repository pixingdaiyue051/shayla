#include "time.h"

namespace TIME {

    Time::Time() {
        _hour = 0;
        _minute = 0;
    }

    Time::Time(int hour, int minute) {
        _hour = hour;
        _minute = minute;
    }

    void Time::addHour(int hour) {
        _hour += hour;
    }

    void Time::addMinute(int minute) {
        _minute += minute;
        int tmp = _minute / 60;
        if (tmp > 0) {
            _hour += tmp;
            _minute %= 60;
//        _minute -= tmp * 60;
        }
    }

    void Time::reset(int hour, int minute) {
        _hour = hour;
        _minute = minute;
    }

    Time Time::operator+(const Time &time) const {
        Time t;
        t._hour = _hour + time._hour;
        t.addMinute(_minute + time._minute);
        return t;
    }

    Time Time::operator*(int plus) const {
        Time t;
        t._hour = _hour * plus;
        t.addMinute(_minute * plus);
        return t;
    }


    Stock::Stock() {
        _company = "";
        _share = 0;
        _price = 0.0;
        _total = 0.0;
    }

    Stock::Stock(long share, double price, const std::string &company) {
        _company = company;
        _share = share < 1 ? 0 : share;
        _price = price;
        _total = _price * _share;
    }

    Stock::~Stock() {
        std::cout << "destructor called ~Stock" << std::endl;
    }

    void Stock::buy(long share, double price) {
        if (share < 1) {
            std::cout << "cannot be negative" << std::endl;
            return;
        }
        _share += share;
        _price = price;
        setTotal();
    }

    void Stock::sell(long share, double price) {
        if (share < 1) {
            std::cout << "cannot sell negative" << std::endl;
            return;
        }
        if (share > _share) {
            std::cout << "cannot sell more than [" << _share << "]" << std::endl;
            return;
        }
        _share -= share;
        _price = price;
        setTotal();
    }

    void Stock::update(double price) {
        _price = price;
        setTotal();
    }

    void Stock::show() {
        using std::cout;
        using std::endl;
        using std::ios_base;
        using std::streamsize;
        ios_base::fmtflags fmt = cout.setf(ios_base::fixed, ios_base::floatfield);
        streamsize prc = cout.precision(3);

        cout << "company:[" << _company << "],"
             << "share:[" << _share << "],"
             << "price:[" << _price << "],"
             << "total:[" << _total << "]" << endl;

        cout.setf(fmt);
        cout.precision(prc);
    }

    Stock::operator double() const {
        return _total;
    }

}