/**
 * 1、命名空间 namespace
 *      1、为避免命名冲突引入namespace 类也是一种命名空间
 *      2、默认的命名空间是全局的没有命名 可以使用::之间访问到
 *      3、::运算符用于访问不同的命名空间下的变量或者函数 默认访问全局非static函数 所有static变量函数都会用匿名命名空间包装
 *      4、支持嵌套设计 访问也是逐层访问使用限定符::
 *      5、支持起别名 namespace alias = 名称过长的命名空间或嵌套命名空间
 * 2、动态存储
 *      1、自动存储(free store) 堆(heap) 会在运行时才创建 动态编译 分配的内存不再被用的时候需要手动释放 不能只依靠程序终结来释放
 *      2、malloc/calloc-free new-delete
 *      3、使用new可以从指定的内存中分配新内存 `new(内存地址) int[20]`
 * 3、变量作用域 连接性
 *      1、自动变量为局部作用域 只能在函数内可见 无连接性 遇到内外同名变量由局部暂时替代全局
 *      2、静态变量有三种分类 外部连接性 内部连接性 无连接性
 *         静态变量的两种声明方式 定义声明(defining declaration) 引用声明(reference declaration)
 *         定义声明会对变量初始化 引用声明不会初始化 使用extern来应用外部文件的变量
 *      3、const声明的全局变量为当前文件内可见 相当于默认加static限定 如果要破除限制就需要加extern
 * 4、函数作用域
 *      1、和变量一样函数作用域类似
 *      2、寻找链接库函数时 可以指定使用的语言 关键字 extern "C" extern "C++"
 * 5、类 封装
 *      将一系列属性和对属性的操作封装成一个整体
 *      保证数据的整体性和安全性
 *      默认属性都是private只能当前类内部访问
 *      类方法默认都是内联函数 所以不宜过长 尽量只提供函数原型
 *      constructor 构造函数 编译器会提供默认构造函数 如果显示创建构造函数编译器不会提供默认构造函数
 *      destructor  析构函数 编译器会提供默认析构函数 如果显示创建析构函数编译器不会提供默认析构函数 该函数由编译器调用 程序中不应该显示调用
 */
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <new>

using namespace std; // c++标准命名空间

// 自定义命名空间
namespace my_scope {
    int param1 = 100;
    char param2 = 'f';
    float param3 = 3.14F;
}

int num = 210; // 定义一个全局变量 外部连接性 既能当前文件内全局访问 外部文件也能无法访问
static int num1 = 21; // 定义一个全局变量 内部连接性 仅在当前文件内全局访问 外部文件无法访问 相当于下面的代码
//namespace {
//    int num1= 21;
//}
extern int external_param; // 引用外部文件的全局变量
void parameter_fnt() {
    static int num2 = 21; // 定义一个全局变量 无连接性 只能在当前函数内访问 但函数没被调用 变量也会提前创建
    int num3 = 200; // 定义一个局部变量 无连接性 只能在当前函数内访问 函数没被调用 变量不会提前创建
    cout << num << num1 << num2 << num3 << endl;
}

void namespace_fnt() {
    int num = 101;
    cout << num << endl;   // 此时输出的是局部变量 局部作用域暂时替代全局作用域
    cout << ::num << endl; // 此时输出的是全局变量
    // 三种方式访问命名空间
    // 1、直接使用
    my_scope::param1 = 20;
    cout << my_scope::param1 << endl;
    // 2、单独引入需要使用的内容
    using my_scope::param1;
    param1 = 201;
    cout << param1 << endl;
    // 3、引入整个命名空间
    using namespace my_scope;
    param1 = 302;
    param2 = 't';
    param3 = 6.98f;
    cout << param1 << param2 << param3 << endl;
}

void ram_fnt() {
    int *a1 = new int(6);
    int *a2 = new int{6};
    int a3 = {6};
    int *arr1 = new int[3]{1, 1, 3};

    int *a4 = new(arr1) int(3); // 从arr1数组所在空间分配内存给a4并初始化为3

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
    delete[] p2; // 销毁数组

    char *p = (char *) malloc(4); // 创建并分配内存 分配连续的32个字节 一旦使用超出32字节程序就会崩溃
    strcpy(p, "123456781234567812345678");
    printf("%llu,%llu,%s\n", sizeof(int), sizeof(*p), p);
    free(p); // 销毁
}


class Data {
private:
    int top{};
    string name;

public:
    void init() {
        top = 0;
        name = "000";
    }

    void show() {
        cout << "top=" << top << ",name=" << name << endl;
    }
};

int main() {
    namespace_fnt(); // 相当于 ::namespace_fnt();
    ram_fnt();

    Data *d = new Data;
    d->init();
    d->show();

    delete d;
    return 0;
}