/**
 * 1、inline内联函数
 *      宏定义
 *          优点:内嵌到调用出 避免函数调用带来的开销
 *          缺点:简单的文本替换 如果设计不够精妙可能带来语义上的错误和意想不到的bug
 *      函数
 *          优点:完成某种抽象操作 避免相同功能重复开发 有类型检查
 *          缺点:每次调用都要再开启入栈出栈操作
 *      内联函数
 *          优点:和宏一样都是替换 可以避免函数入栈出栈操作
 *          缺点:在函数体内会出现多个替换副本增加代码段空间 更占内存
 *          适用场景:函数体小且频繁调用 <=5行 非递归函数
 * 2、形参 实参 默认参数
 *      形参可以设置一个默认参数 当没有参数传入时就使用默认参数作为实参
 *      设置默认参数必须按照从右向左顺序设置 不能跳跃
 *      实参个数+默认参数个数>=形参个数
 * 3、函数重载(静多态)
 *      函数名相同 参数类型不同 参数顺序不同 参数个数不同
 *      返回值不同不算重载
 *      使用name mangling(倾轧)修改函数名实现重载 void fnt(char c, int i) --> fnt_c_i()
 *      有默认参数的函数不能重载
 * 4、运算符重载
 *      operator实现运算符功能重载 只能实现cpp已支持的操作符
 *      不能改变原操作符优先级和运算意义 不能创建新的运算符
 * 5、传参数方式
 *      传值  复制形参再赋值实参 数据之间不关联 适用本身数值不多内存占用不大的情况
 *      传指针 实际传递是变量的内存地址 数据互相关联 效率高但也有数据被篡改的危险 可使用const作用于形参保证数据不可变
 *      传引用 改传副本为传原始数据 避免直接暴露内存地址
 * 6、编程模板 通用编程
 *      把不同类型的同一类操作合并为同一种函数模板
 *      编程模板可以重载
 *      使用显式具体化(explicit specialization)对特定类型做处理
 */
#include <iostream>

using namespace std;

#define SQR(x) ((x) * (x))

inline int sqr(int x) {
    return x * x;
}

void inline_fnt() {
    int x = 0;
    while (x < 5) {
        cout << SQR(x++) << endl;
        cout << sqr(x++) << endl;
    }
}

struct Emp {
    float weight;
    float height;
};

Emp operator+(Emp &p1, Emp &p2) {
    return {.weight = p1.weight + p2.weight, .height = p1.height + p2.height};
}

void params_fnt(Emp p, int arr[], int param1 = 10) {
    p.weight = 11.10F;
    p.height = 10.1F;
    arr[0] = 32;
    param1 = 90;

    cout << "p address:" << &p << ",arr address:" << arr << ",param1 address:" << &param1 << endl;
    cout << p.weight << "," << p.height << "," << arr[0] << "," << param1 << endl;
}

void params_fnt(Emp *p, int *arr, int &parma1) {
    p->weight = 11.10F;
    p->height = 10.1F;
    *arr = 32;
    parma1 = 90;

    cout << "p address:" << &p << ",arr address:" << arr << ",param1 address:" << &parma1 << endl;
    cout << p->weight << "," << p->height << "," << *arr << "," << parma1 << endl;
}

template<typename T>
void template_fnt(T &t1, T &t2) {
    T tmp = t1;
    t1 = t2;
    t2 = tmp;
}

template<> void template_fnt<Emp>(Emp &p1, Emp &p2) {
    float tmp = p1.weight;
    p1.weight = p2.weight;
    p2.weight = tmp;
}


int main() {
    inline_fnt();

    Emp p1 = {1.1F, 2.1F};
    Emp p2 = {.weight = 2.4F, .height = 4.13F};
    Emp p3 = p1 + p2; // 相当于 Emp p3 = operator+(p1, p2);
    cout << p3.weight << "," << p3.height << endl;
    int arr[] = {1, 2, 3};
    int param1 = 12;

    cout << "p address:" << &p1 << ",arr address:" << arr << ",param1 address:" << &param1 << endl;
    cout << p1.weight << "," << p1.height << "," << arr[0] << "," << param1 << endl;

    params_fnt(p1, arr, param1);
    cout << p1.weight << "," << p1.height << "," << arr[0] << "," << param1 << endl;
    params_fnt(&p1, arr, param1);
    cout << p1.weight << "," << p1.height << "," << arr[0] << "," << param1 << endl;

    int a1 = 0;
    int a2 = 2;
    template_fnt(a1, a2);
    cout << a1 << "," << a2 << endl;

    template_fnt(p1, p2);
    cout << p1.weight << "," << p2.weight << endl;
    return 0;

}