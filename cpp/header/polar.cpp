#include <iostream>
#include <cmath>
#include "polar.h"

void rect_to_polar(const Rect &rect, Polar &polar) {
    polar.distance = sqrt(rect.x * rect.x + rect.y * rect.y);
    polar.angle = atan2(rect.y, rect.x);
}

void show_polar(const Polar &polar) {
    std::cout << "polar=[" << polar.distance << "," << polar.angle << "]" << std::endl;
}