#ifndef HT_C_STOCK_H
#define HT_C_STOCK_H

#include <string>

class Stock {
private:
    std::string _company;
    long _share;
    double _price;
    double _total;
public:
    Stock(); // 如果构造函数所有参数都是默认值 那默认构造函数可以省略

    Stock(const std::string &company, long share, double price);

    void set_total() {
        _total = _price * _share;
    }

    void buy(long share, double price);

    void sell(long share, double price);

    void update(double price);

    void show();
};

#endif
