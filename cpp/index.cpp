#include <iostream>

using namespace std;


#include <bitset>

/**
 * c++ 输入输出
 */
void io_fnt() {

    // 默认按照十进制显，不论用什么进制赋值
    int a = 1024;
    cout << a << endl;
    a = 0b0010000000000; // 0b开头表示使用二进制赋值
    cout << a << endl;
    a = 02000; // 0开头表示使用八进制赋值
    cout << a << endl;
    a = 0x400; // 0x开头表示使用十六进制赋值
    cout << a << endl;

    cout << "0b" << bitset<16>(a) << endl; // 二进制输出 使用bitset指定输出长度

    cout << "0" << oct << a << endl; // 八进制输出
    cout << "0x" << hex << a << endl; // 十六进制输出

//    int num, data;
//    cin >> num >> data; // 按照空格依次获取输入赋值num和data
//    cout << "num=" << num << ",data=" << data << endl;
//
//    string str;
//    cin >> str; // 可以最大输入str.max_size()字符
//    cout << "string max len = " << str.max_size() << endl;
//    cout << str << endl;
}

#include <climits>

/**
 * 操作数
 */
void ope_fnt() {
//    // const 作用于以后的变量类型不可变
//    // 此时a和b都是不可变的
//    const int a = 1;
//    int const b = 2;
//    // c++不能通过使用指针的形式间接修改const变量
//    // int *pc = &a;
//    // printf("%d\n", a);
//    // *pc = 100;
//    // printf("%d\n", a);
//
//    // 此时*pm不可变 pm是指针本质上是内存上的地址仍然可变
//    const int *pm = (int *) malloc(10);
//    printf("%p,%d\n", pm, *pm);
//    pm = &a;
//    printf("%p,%d\n", pm, *pm);
//
//    // c++扩充了bool类型 可以直接使用 并且可以赋值除true和false外其他整数
//    bool b1 = true;
//    printf("%d\n", b1);
//    b1 = 21; // 此时会自动转变为false(0)或true(非0) 赋其他值没意义
//    printf("%d\n", b1);
//    // int g1 = b1 * 4;
//    // printf("%d\n", g1);
//
//    // 表达式可以赋值也可以被赋值
//    int v1, v2;
//    v1 = v2 = 100; // 等同于 v1 = (v2 = 100); 先对v2赋值 再将(v2 = 100)表达式的结果即v2赋值给v1
//    (v1 = v2) = 50; // (v1 = v2)是一个表达式 然后对其结果即v1再赋值 一共完成了2次对v1的赋值 v2始终没变
//    printf("%d,%d\n", v1, v2);

    // 基本数据类型
    cout << sizeof(int) << endl; // int 占4byte=32bit
    cout << CHAR_BIT << endl; // 1byte所占的bit数
    cout << UCHAR_MAX << "," << USHRT_MAX << "," << UINT_MAX << "," << ULONG_MAX << "," << ULLONG_MAX << "," << endl;
    cout << CHAR_MIN << "," << SHRT_MIN << "," << INT_MIN << "," << LONG_MIN << "," << LLONG_MIN << "," << endl;
    cout << CHAR_MAX << "," << SHRT_MAX << "," << INT_MAX << "," << LONG_MAX << "," << LLONG_MAX << "," << endl;

    short s0 = 32768;
    unsigned short s1 = 65536;
    cout << s0 << "," << s1 << endl;
}

#include <cstdlib>
#include <cstring>

/**
 * 内存的分配与销毁 new/delete  malloc/free
 */
void ram_fnt() {
    char *p1 = new char('m'); // 创建并分配内存
    strcpy(p1, "12345678");
    printf("%llu,%llu,%s\n", sizeof(char), sizeof(*p1), p1);
    delete p1; // 销毁

    char *p2 = new char[4]; // 创建数组
    p2[0] = '3';
    p2[1] = 'd';
    p2[2] = '4';
    p2[3] = 'd';
    printf("%llu,%llu,%s\n", sizeof(char), sizeof(*p2), p2);
    delete[]p2; // 销毁数组

    char *p = (char *) malloc(4); // 创建并分配内存 分配连续的32个字节 一旦使用超出32字节程序就会崩溃
    strcpy(p, "123456781234567812345678");
    printf("%llu,%llu,%s\n", sizeof(int), sizeof(*p), p);
    free(p); // 销毁
}

/**
 * 1、隐式类型转换
 *      自动转换 一般是数据类型间的转换从小到大
 * 2、强制类型转换
 *      c++保留的c的强制类型转换方式 (int) xx
 *      static_cast 通常用于将一种数据类型的值强制转换为另一种数据类型的值
 *      dynamic_cast 通常用于将一个基类指针或引用转换为派生类指针或引用
 *      const_cast 只能用于转换掉 const 属性，不能改变对象的类型
 *      reinterpret_cast 通常用于在不同的数据类型之间进行转换
 */
void cast_fnt() {
    int a1 = 3;
    float f1 = a1 + 4;   // 存在向上的自动类型转换
    double d1 = f1 + a1; // 存在向上的自动类型转换
    cout << "a1=" << a1 << ",f1=" << f1 << ",d1=" << d1 << endl;

    // static_cast
    float f2 = 4.56333;
    int a2 = static_cast<int>(f2);
    cout << "f2=" << f2 << ",a2=" << a2 << endl;

    // const_cast 脱除const
    const int o1 = 510;
    int *o2 = const_cast<int *>(&o1);
    int &o3 = const_cast<int &>(o1);
    *o2 = 200;
    cout << "o1=" << o1 << ",o2=" << *o2 << ",o3=" << o3 << endl;
    o3 = 400;
    cout << "o1=" << o1 << ",o2=" << *o2 << ",o3=" << o3 << endl;
}

/**
 * 1、形参 实参 默认参数
 *      实参个数+默认参数个数>=形参个数
 *      设置默认参数必须按照从右向左顺序设置 不能跳跃
 *      形参可以设置一个默认参数 当没有参数传入时就使用默认参数作为实参
 * 2、有默认参数的函数不能再重载
 *      一定程度上破坏了多态
 */
void params_fnt(int a = 10) {
    cout << "void params(int a = 10)" << a << endl;
}

/**
 * inline内联函数
 *      宏定义
 *          优点:内嵌到调用出 避免函数调用带来的开销
 *          缺点:简单的文本替换 如果设计不够精妙可能带来语义上的错误和意想不到的bug
 *      函数
 *          优点:完成某种抽象操作 避免相同功能重复开发 有类型检查
 *          缺点:每次调用都要再开启入栈出栈操作
 *      内联函数
 *          优点:和宏一样都是替换 可以避免函数入栈出栈操作
 *          缺点:在函数体内会出现多个替换副本增加代码段空间
 *          适用场景:函数体小且频繁调用 <=5行
 */
#define SQR(x) ((x) * (x))

inline int sqr(int x) {
    return x * x;
}

void inline_fnt() {
    int x = 0;
    while (x < 5) {
        cout << sqr(x++) << endl;
        cout << SQR(x++) << endl;
    }
}

int main(int argc, const char *argv[]) {
    cout << "hello world" << endl;
//    io_fnt();
    ope_fnt();
//    ram_fnt();
//    cast_fnt();
//    params_fnt();
//    inline_fnt();
    return 0;
}