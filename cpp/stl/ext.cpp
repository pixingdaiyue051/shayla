#include <iostream>

using namespace std;

#include <bitset>
#include <climits>

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

    ios_base::fmtflags flg = cout.setf(ios_base::fixed, ios_base::floatfield);
    streamsize prc = cout.precision(3);

    cout.setf(flg);
    cout.precision(prc);

//    int number, data;
//    cin >> number >> data; // 按照空格依次获取输入赋值num和data
//    cout << "number=" << number << ",data=" << data << endl;

//    const int MAX_IN = 12;
//    char ch[MAX_IN], ch1[MAX_IN];
//    cin.getline(ch, MAX_IN).getline(ch1, MAX_IN);
//    cout << ch << "," << ch1 << endl;


//    char ch = '1';
//    int len = 0;
//    do {
//        cin.get(ch);
//        cout << ch;
//        ++len;
//    } while (ch != '#'); // 检测输入不是特殊输入字符
//    do {
//        cin.get(ch);
//        cout << ch;
//        ++len;
//    } while (!cin.fail()); // 检测EOF cin.eof() 或 cin.fail() 一般为CRTL+Z 然后ENTER就是EOF
//    while(cin.get(ch)) {
//        cout << ch;
//        ++len;
//    }
//    int ch1 = 0;
//    while ((ch1 = cin.get()) != EOF) {
//        cout << ch1; // cout << char(ch1);
//        ++len;
//    }
//    cout << "len=" << len << endl;

    const int MAX = 5;
    cout << "please input " << MAX << "integers:" << endl;
    int goat[MAX] = {0, 0, 0, 0, 0};
    for (int i = 0; i < MAX; ++i) {
        while (!(cin >> goat[i])) {
            cin.clear();
            while ((cin.get()) != '\n')
                continue;
            cout << "please input integer!" << endl;
        }
    }
    double total = 0.0;
    for (int j = 0; j < MAX; ++j) {
        cout << goat[j] << endl;
        total += goat[j];
    }
    double avg = total / MAX;
    cout << "total:" << total << ",avg:" << avg << endl;

}

/**
 * 操作数
 */
void ope_fnt() {
    // 基本数据类型
    cout << sizeof(int) << endl; // int 占4byte=32bit
    cout << CHAR_BIT << endl; // 1byte所占的bit数
    cout << UCHAR_MAX << "," << USHRT_MAX << "," << UINT_MAX << "," << ULONG_MAX << "," << ULLONG_MAX << endl;
    cout << CHAR_MIN << "," << SHRT_MIN << "," << INT_MIN << "," << LONG_MIN << "," << LLONG_MIN << endl;
    cout << CHAR_MAX << "," << SHRT_MAX << "," << INT_MAX << "," << LONG_MAX << "," << LLONG_MAX << endl;

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
//
//    char s0 = 7;
//    unsigned char s1 = 129;
//    cout << s0 << "," << s1 << endl;
//    cout.put(s0);
//
//    wchar_t c = L'6';
//    char16_t c1 = u'3';
//    char32_t c2 = U'H';
//    cout << c << "," << c1 << "," << c2 << endl;

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

int main() {
//    io_fnt();
//    ope_fnt();
//    cast_fnt();
    return 0;
}