#include <iostream>
#include "stock.h"

Stock::Stock() {
    _company = "";
    _share = 0;
    _price = 0.0;
    _total = 0.0;
}

Stock::Stock(const std::string &company, long share, double price) {
    _company = company;
    _share = share < 1 ? 0 : share;
    _price = price;
    _total = _price * _share;
}

void Stock::buy(long share, double price) {
    using std::cout;
    using std::endl;
    if (share < 1) {
        cout << "cannot be negative" << endl;
        return;
    }
    _share += share;
    _price = price;
    set_total();
}

void Stock::sell(long share, double price) {
    using std::cout;
    using std::endl;
    if (share < 1) {
        cout << "cannot be negative" << endl;
        return;
    }
    if (share > _share) {
        cout << "cannot be more than _share:[" << _share << "]" << endl;
        return;
    }
    _share -= share;
    _price = price;
    set_total();
}

void Stock::update(double price) {
    _price = price;
    set_total();
}

void Stock::show() {
    using std::cout;
    using std::endl;
    using std::ios_base;
    using std::streamsize;
    ios_base::fmtflags fmt = cout.setf(ios_base::fixed, ios_base::floatfield);
    streamsize prc =  cout.precision(3);

    cout << "company:[" << _company << "],"
         << "share:[" << _share << "],"
         << "price:[" << _price << "],"
         << "total:[" << _total << "]" << endl;

    cout.setf(fmt);
    cout.precision(prc);
}
