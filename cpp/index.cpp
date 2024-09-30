#include <iostream>
#include "header/polar.h"
#include "header/stock.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "hello world" << endl;
    cout << "argc:" << argc << ",argv:";
    for (int i = 0; i < argc; ++i) {
        cout << argv[i] << "\t";
//        cout << *(argv+i) << "\t";
    }
    cout << endl;
    Polar polar = {};
    Rect rect = {10.5, 11.5};
    rect_to_polar(rect, polar);
    show_polar(polar);

    Stock s1 = Stock("nkl", 1, 34.21);
    s1.update(33.1);
    s1.show();

    Stock *ps2 = new Stock("bgl", 3, 42.11);
    ps2->sell(1, 4.2);
    ps2->sell(32, 331);
    ps2->buy(1, 3.3);
    ps2->show();
    return 0;
}