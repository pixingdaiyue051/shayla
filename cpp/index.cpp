#include <iostream>
#include <cstdlib> // srand() rand()
#include <ctime> // time()
#include "header/time.h"
#include "header/coordinate.h"
#include "header/player.h"
#include "algorithm/string.h"

using namespace std;

void time() {
    using namespace TIME;
    srand(time(nullptr));
    Time t1 = Time(rand(), rand());
    Time t2 = Time(rand(), rand());
    Time t3 = t1 + t2;
    t3.show();
    t3 = t3 * 4;
    t3.show();
    t3 = 4 * t3;
    t3.show();
    cout << t3 << endl;

    Stock s1 = Stock(1, 34.21, "nkl");
//    Stock s1 = 1; // 有可以匹配到的单参数构造函数自动类型转换 使用explicit阻止
//    Stock s1 = Stock(1); // 即使使用explicit阻止自动类型转换 传统方法也可以继续使用
//    Stock s1(1);
//    double d1 = s1; // 定义了转换函数可以直接实现自动类型转换 使用explicit阻止
//    auto d1 = double(s1); // 即使使用explicit阻止自动类型转换 传统方法也可以继续使用
//    double d1(s1);
    s1.update(33.1);
    s1.show();
    auto *s2 = new Stock(3, 42.11, "bgl");
    s2->sell(1, 4.2);
    s2->sell(32, 331);
    s2->buy(1, 3.3);
    s2->show();
    delete s2; // 自动调用析构函数
}

void coordinate() {
    using namespace COORDINATE;
    Rect rect = {3.0, 4.0};
    Polar polar = {10.0, 405.0 / RAD_2_DEG};
    Polar p1 = rect2polar(rect);
    Rect r1 = polar2Rect(polar);
    cout << "[" << r1.x << "," << r1.y << "]" << ",[" << p1.mag << "," << p1.ang * RAD_2_DEG << "]" << endl;
    Vector v1 = Vector(3.0, 4.0);
    Vector v2 = Vector(10.0, 45.0 / RAD_2_DEG, POLAR);
    Vector v3 = v1 + v2;
    cout << v3 << endl;
}

void stringFnt1(String s) {
    cout << s << endl;
} // 传值会默认对类成员进行复制生成临时变量 为防止出错应提供深度复制构造函数 函数结束时自动调用析构函数

void stringFnt2(String &s) {
    cout << s << endl;
} // 传引用不存上述问题 因此对类成员 结构体 共同体等应尽量使用引用

void stringFnt() {
    String s1("ok");
    String s2 = "ok12";
    String s3(s1);
    String s4 = s2;
    s3 = "442";
    s4 = s1;
//    stringFnt1(s1);
//    stringFnt2(s4);
    int tmp1 = s4.getObjNum();
    int tmp2 = String::getObjNum();
    cout << tmp1 << tmp2 << endl;
}

void player() {
//    Player p1("p1", "p1-back");
//    RatePlayer rp1(40, p1);
////    cout << p1.getName() << p1.getInfo() << endl;
////    cout << rp1.getRate() << rp1.getName() << rp1.getInfo() << endl;
//
////    Player p = rp1; // 可行
////    RatePlayer rp = p1; // 无法赋值
//
//    Player *p3 = new RatePlayer(50, p1);
//    Player &p4 = rp1;
////    cout << p3->getName() << p3->getInfo() << endl;
////    cout << p4.getName() << p4.getInfo() << endl;
//    delete p3;

    BaseBrass *b1 = new Brass("zs", 40051240, 521.6);
    BaseBrass *b2 = new BrassPlus("ls", 40025458, 5100.67, 10000.0);
    b1->deposit(100);
    b1->withdraw(5000000);
    b2->withdraw(50000000000);

    delete b2;
    delete b1;
}

int main(const int argc, const char *argv[]) {
    cout << "hello world" << endl;
    cout << "argc:" << argc << ",argv:";
    for (int i = 0; i < argc; ++i) {
        cout << argv[i] << "\t"; // cout << *(argv+i) << "\t";
    }
    cout << endl;

//    time();
//    coordinate();
//    stringFnt();
    player();

    return 0;
}