/**
 * 1、引用 ref
 *      引用类型必须和原变量类型一致
 *      并不分配内存
 *      是一种关系声明 相当于起别名
 *      声明时必须针对明确的类型进行引用
 *      可以对引用再次引用
 *      &前有类型表示引用 其他都是取地址操作
 *      c语言中没有这种用法
 * 2、指针与引用
 *      引用本质上还是对指针的一次封装
 *      有指针的指针        int **
 *      有指针的引用        int *&
 *      没有引用的指针      int &*
 *      没有引用的引用      int &&
 * 3、引用与数组
 *      有数组的引用
 *      没有引用数组
 * 4、const引用
 *      禁止通过修改引用来修改引用对象数据
 *      可以对非const变量和const变量引用
 *      可以对常量引用
 *      可以不同类型之间引用(存在隐式转换)
 *      可以对表达式引用
 */
#include <iostream>

using namespace std;

void ref_fnt() {
    int a = 100;
    int b = 200;
    int &ra = a;   // int & 为a起一个引用类型(别名)
    int &ra1 = ra; // 可以对引用再次引用
    // int &ra = b; // 编译错误 error: redeclaration
    // ra = b; // 通过修改应用来修改引用对象数据    相当于a = b;
    printf("%d,%d,%d\n", a, ra, ra1);
    printf("%p,%p,%p\n", &a, &ra, &ra1);

    int *p = &a;   // 定义一个指针
    int **pp = &p; // 定义指向该指针的指针(二级指针)
    int *&pr = p;  // 定义指针的引用
    printf("%d,%d,%d\n", *p, **pp, *pr);
    printf("%p,%p,%p\n", p, *pp, pr);
    int &r = a; // 定义一个引用
    // int &*rp1 = &a; // 编译错误
    // int &&rp2 = a; // 编译错误

    int arr[] = {100, 200, 300}; // 定义一个数组
    int(&refarr)[3] = arr;       // 定义数组的引用 相当于int[3] &refarr = arr;但不支持这种写法
    // int &refarr1[3] = arr; // 编译错误

    const int t1 = 100;
    // int &rt1 = t1; // 编译错误 const类型的引用必须也是const
    const int &rt1 = t1;
    // int &r01 = 21; // 编译错误 无法直接对常量引用
    const int &r01 = 21;
    float f1 = 10.421;
    // int &rf1 = f1; // 编译错误 类型不匹配
    const int &rf1 = f1;
    const float &rf2 = f1;
    const float &rf3 = rf1;
    f1 = 30.103; // 此时修改f1 rf1和rf3不会改变 rf2会被修改
    cout << "f1=" << f1 << ",rf1=" << rf1 << ",rf2=" << rf2 << ",rf3=" << rf3 << endl;
    float f2 = 5.321;
    // float &rrf1 = f2 + 4.32; // 编译错误 无法对表达式引用
    const float &rrf1 = f2 + 4.32;
}

/**
 * 交换变量数值 c
 * 传参需要使用指针
 */
void swap_c(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * 交换变量数值 cpp
 * 传参使用引用
 */
void swap_cpp(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

/**
 * 交换数据
 * 由于不能直接修改指针的内容 所以需要借助二级指针获得指针本身的内存地址
 */
void swap_c1(char **p, char **q) {
    char *tmp = *p;
    *p = *q;
    *q = tmp;
}

/**
 * 交换数据
 * 由于使用了引用 p和q就是指向数据的指针
 */
void swap_cpp1(char *&p, char *&q) {
    char *tmp = p;
    p = q;
    q = tmp;
}

void ref_fnt1() {
    int a = 10;
    int b = 20;
    cout << "a=" << a << ",b=" << b << endl;
    swap_c(&a, &b);
    cout << "a=" << a << ",b=" << b << endl;
    swap_cpp(a, b);
    cout << "a=" << a << ",b=" << b << endl;

    char *p = "p123";
    char *q = "q321";
    cout << "p=" << p << ",q=" << q << endl;
    swap_c1(&p, &q);
    cout << "p=" << p << ",q=" << q << endl;
    swap_cpp1(p, q);
    cout << "p=" << p << ",q=" << q << endl;
}

int main(int argc, const char *argv[]) {
    ref_fnt1();
    return 0;
}