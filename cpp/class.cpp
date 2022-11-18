/**
 * 类 封装
 *      将一系列属性和对属性的操作封装成一个整体
 *      保证数据的整体性和安全性
 *      默认属性都是private只能当前类内部访问
 */
#include <iostream>

using namespace std;

class Data {
private:
    int top{};
    string name;

public:
    void init() {
        top = 0;
        name = "000";
    }

    void print() {
        cout << "top=" << top << ",name=" << name << endl;
    }
};

int main(int argc, const char *argv[]) {
    Data d;
    d.init();
    d.print();
    return 0;
}