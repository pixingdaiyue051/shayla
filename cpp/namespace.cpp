/**
 * 命名空间 namespace
 *      1、为避免命名冲突引入namespace 类也是一种命名空间
 *      2、默认的命名空间是全局的没有命名 可以使用::之间访问到
 *      3、::运算符用于访问不同的命名空间下的变量或者函数 默认访问全局
 *      4、支持嵌套设计 访问也是逐层访问
 */
#include <iostream>

using namespace std; // c++标准命名空间

int num = 210; // 定义一个全局变量

// 自定义命名空间
namespace myscope {
    int aint = 100;
    char cchar = 'f';
    double ddouble = 3.14f;
}


void test() {
    int num = 101;
    cout << num << endl;   // 此时输出的是局部变量
    cout << ::num << endl; // 此时输出的是全局变量
}

void test1() {
    test(); // 相当于 ::test(); 如果有static修饰函数 就不能使用::访问

    // 三种方式访问命名空间
    // 1、直接使用
    myscope::aint = 20;
    cout << myscope::aint << endl;
    // 2、单独引入需要使用的内容
    using myscope::aint;
    aint = 201;
    cout << aint << endl;
    // 3、引入整个命名空间
    using namespace myscope;
    aint = 302;
    cchar = 't';
    ddouble = 6.98f;
    cout << aint << cchar << ddouble << endl;
}


int main(int argc, const char *argv[]) {
    test1();
    return 0;
}