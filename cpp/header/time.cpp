#include "time.h"

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