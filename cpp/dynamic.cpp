/**
 * 多态
 * 1、函数重载(静多态)
 *      函数名相同 参数类型不同 参数顺序不同 参数个数不同
 *      返回值不同不算重载
 *      使用name mangling(倾轧)修改函数名实现重载  使用extern "C"结束语句倾轧 表示使用c语言语法编译
 *      void fnt(char c, int i) --> fnt_c_i()
 * 2、运算符重载
 *      operator实现运算符功能重载
 */
#include <iostream>

using namespace std;

void fnt(char c, int i) {
    cout << "void fnt(char c, int i)" << endl;
}

void fnt(int i) {
    cout << "void fnt(int i)" << endl;
}

void fnt(char c) {
    cout << "void fnt(char c)" << endl;
}

extern "C"
{
void ptn(char c) {
    printf("%-5c%-5.3f\n", c, 4.23442);
}
}

struct Com {
    int i;
    int j;
};

Com add(Com a, Com b) {
    int i = a.i + b.i;
    int j = a.j + b.j;
    return {.i = i, .j = j};
}

Com operator+(Com a, Com b) {
    int i = a.i + b.i;
    int j = a.j + b.j;
    return {.i = i, .j = j};
}

/**
 * 枚举 枚举是扩充类
 * 只能赋值枚举内的数值
 * 可以为每个枚举值单独赋特殊值 默认从0开始
 */
enum WEEK {
    MON = 1, TUS = 2, WEN = 3, THU = 4, FRI = 5, SAT = 6, SUN = 7
};


int main(int argc, const char *argv[]) {
    Com a = {.i = 3, .j = 6};
    Com b = {.i = 1, .j = 9};
    Com c = a + b; // 相当于c = operator+(a, b);或者c = add(a, b);
    printf("%-5d%-5d\n", c.i, c.j);

    WEEK b2 = MON;
    printf("%d\n", b2);
    int g2 = b2 * 4;
    printf("%d\n", g2);

    return 0;
}