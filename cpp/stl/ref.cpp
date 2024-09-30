/**
 * 1、引用 ref
 *      引用类型必须和原变量类型一致 声明时必须针对明确的类型进行初始化
 *      可以对引用再次引用
 *      是一种关系声明 相当于起别名 并不分配内存
 *      &前有类型表示引用 其他都是取地址操作 c语言中没有这种用法
 *      主要用途是作为函数形参传入参数 改传副本为传原始数据
 *      `int &ra = a` 相当于 `int * const ra = &a`的伪装
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
 *      可以对非const变量和const变量引用 有下列两种情况传参会使用临时变量
 *      1.当实参类型不正确但是可以隐式转换成形参类型
 *      2.当实参类型匹配但实参不是左值(变量、数组元素、结构成员、引用和解除引用的指针...)
 *      尽可能将引用生命为const理由有三
 *      1.可以避免无意中修改数据的编程错误
 *      2.使函数能够处理const和非const实参 否则将只能接受非const数据
 *      3.const引用使函数能够正确生成并使用临时变量
 * 5、作用
 *      对参数作解引用 方便引用原始数据
 *      应当作用于结构体 共同体 类等内存占用较大的类型 不宜使用在基本数据类型上
 *      引用主要用在函数传参避免频繁创建销毁内存
 * 6、右值引用
 *      针对右值表达式的引用 需要使用&&标识 不常用
 *      左值是位于=左侧固定的变量 数组变量 指针 解引用数值等等
 *      右值是位于=右侧的表达式 函数 作用值等等
 */
#include <iostream>

using namespace std;

void ref_fnt() {
    int a = 100;
    int b = 200;
    int &ra = a;   // int & 为a起一个引用类型(别名) int * const ra = &a
    int &ra1 = ra; // 可以对引用再次引用
//    int &ra = b; // 编译错误 error: redeclaration
//    ra = b; // 通过修改应用来修改引用对象数据    相当于a = b;
    printf("%d,%d,%d\n", a, ra, ra1);
    printf("%p,%p,%p\n", &a, &ra, &ra1);

    int *p = &a;   // 定义一个指针
    int **pp = &p; // 定义指向该指针的指针(二级指针)
    int *&pr = p;  // 定义指针的引用
    printf("%d,%d,%d\n", *p, **pp, *pr);
    printf("%p,%p,%p\n", p, *pp, pr);

//    int &r = a; // 定义一个引用
//    int &*rp1 = &a; // 编译错误
//    int &&rp2 = a; // 编译错误

    int arr[] = {100, 200, 300}; // 定义一个数组
    int(&refarr)[3] = arr;       // 定义数组的引用 arr是数组地址 refarr相当于arr的别名
    // int &refarr1[3] = arr; // 编译错误 不支持这种写法
    cout << *arr << "," << *(refarr + 1) << endl;

    const int t1 = 100;
    // int &rt1 = t1; // 编译错误 const类型的引用必须也是const
    const int &rt1 = t1;
    // int &r01 = 21; // 编译错误 无法直接对常量引用
    const int &r01 = 21; // 此时会对21创建临时变量 再将ra设置成临时变量的引用
    // float &rrf1 = t1 + 4.32; // 编译错误 无法对表达式引用
    const float &rrf1 = t1 + 4.32; // 此时会对表达式创建临时变量 再将rrf1设置成临时变量的引用
    cout << t1 << "," << rt1 << "," << r01 << "," << rrf1 << endl;

    float f1 = 10.421;
    // int &rf1 = f1; // 编译错误 类型不匹配
    const int &rf1 = f1;
    const float &rf2 = f1;
    const float &rf3 = rf1;
    f1 = 30.103; // 此时修改f1 rf1和rf3不会改变 rf2会被修改
    cout << "f1=" << f1 << ",rf1=" << rf1 << ",rf2=" << rf2 << ",rf3=" << rf3 << endl;

    int &&o1 = t1 + 23 - 10; // 右值引用
    cout << o1 << endl;
}

/**
 * 传参需要使用指针
 */
void swap_p(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * 传参使用引用
 */
void swap_r(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swap_fnt() {
    int t1 = 20;
    int t2 = 31;
    cout << "t1=" << t1 << ",t2=" << t2 << endl;
    swap_p(&t1, &t2);
    cout << "t1=" << t1 << ",t2=" << t2 << endl;
    swap_r(t1, t2);
    cout << "t1=" << t1 << ",t2=" << t2 << endl;
}

int main() {
    ref_fnt();
//    swap_fnt();
    return 0;
}