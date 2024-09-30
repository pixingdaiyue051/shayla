#ifndef HT_C_POLAR_H
#define HT_C_POLAR_H
struct Polar {
    double distance;
    double angle;
};

struct Rect {
    double x;
    double y;
};

void rect_to_polar(const Rect &rect, Polar &polar);

void show_polar(const Polar &polar);

#endif