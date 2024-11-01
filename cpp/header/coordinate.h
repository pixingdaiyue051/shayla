/**
 * 一、直角坐标转换为极坐标
 * 计算‌极径ρ‌：
 * 使用公式 ρ = √(x² + y²) 计算点到原点的距离，即极径。
 * 计算极角θ‌：
 * 使用公式 tanθ = y/x 计算点与原点的连线与极轴的夹角。需要注意的是，当x=0时，若y为正，则θ=90°；若y为负，则θ=270°。
 * 二、极坐标转换为直角坐标
 * 计算‌横坐标x‌：
 * 使用公式 x = ρcosθ 计算点的横坐标。
 * 计算‌纵坐标y‌：
 * 使用公式 y = ρsinθ 计算点的纵坐标。
 */
#ifndef SHAYLA_VECTOR_H
#define SHAYLA_VECTOR_H

#include <iostream>
#include <cmath>

namespace COORDINATE {

    const double RAD_2_DEG = 45.0 / atan(1.0); // 约等于57.2958

    struct Polar {
        double mag;
        double ang;
    };

    struct Rect {
        double x;
        double y;
    };

    Polar rect2polar(const Rect &rect);

    Rect polar2Rect(const Polar &polar);

    enum Mode {
        RECT, POLAR
    };

    class Vector {
    private:
        double _x;
        double _y;
        double _mag;
        double _ang;
        Mode _mode;
    public:
        Vector();

        Vector(double val1, double val2, Mode mode = RECT);

        void reset(double val1 = 0.0, double val2 = 0.0, Mode mode = RECT);

        Vector operator+(const Vector &v) const;

        Vector operator-(const Vector &v) const;

        Vector operator-() const; //向量取反

        Vector operator*(double n) const;

        friend Vector operator*(double n, const Vector &v);

        friend std::ostream &operator<<(std::ostream &os, const Vector &v);
    };
}

#endif