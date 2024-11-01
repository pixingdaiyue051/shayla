#include "coordinate.h"

namespace COORDINATE {

    Polar rect2polar(const Rect &rect) {
        double mag = sqrt(rect.x * rect.x + rect.y * rect.y);
        double ang = atan2(rect.y, rect.x);
        return {.mag=mag, .ang = ang};
    }

    Rect polar2Rect(const Polar &polar) {
        double x = polar.mag * cos(polar.ang);
        double y = polar.mag * sin(polar.ang);
        return {.x=x, .y=y};
    }

    Vector::Vector() {
        _mode = RECT;
        _x = _y = _mag = _ang = 0.0;
    }

    Vector::Vector(double val1, double val2, Mode mode) {
        reset(val1, val2, mode);
    }

    void Vector::reset(double val1, double val2, Mode mode) {
        _mode = mode;
        if (RECT == mode) {
            _x = val1;
            _y = val2;
            _mag = sqrt(_x * _x + _y * _y);
            _ang = atan2(_y, _x);
            return;
        }
        if (POLAR == mode) {
            _mag = val1;
            _ang = val2;
            _x = _mag * cos(_ang);
            _y = _mag * sin(_ang);
            return;
        }
        std::cout << "error mode cannot init" << std::endl;
    }

    Vector Vector::operator+(const Vector &v) const {
        return {_x + v._x, _y + v._y};
    }

    Vector Vector::operator-(const Vector &v) const {
        return {_x - v._x, _y - v._y};
    }

    Vector Vector::operator-() const {
        return {-_x, -_y};
    }

    Vector Vector::operator*(double n) const {
        return {n * _x, n * _y};
    }

    Vector operator*(double n, const Vector &v) {
        return v * n;
    }

    std::ostream &operator<<(std::ostream &os, const Vector &v) {
        os << "[" << v._x << "," << v._y << "]" << ",[" << v._mag << "," << v._ang * RAD_2_DEG << "]";
        return os;
    }
}