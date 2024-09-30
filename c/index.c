#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define N 10
#define FNT(n) n * 21
#define ADD(a, b) (a + b)
#define SUB(a, b) (a - b)
#define MUT(a, b) (a * b)
#define DIV(a, b) (a / b)

#define MAX(a, b)                      \
    (                                  \
        {                              \
            typeof(a) _a = a;          \
            typeof(a) _b = b;          \
            (void)(&_a == &_b);        \
            (_a) > (_b) ? (_a) : (_b); \
        })

/**
 *  利用宏定义代替函数实现
 *  由于宏定义在代码编译阶段是简单代码片段替换 某些情况下会比使用函数更高效
 **/
void def() {
    float a1 = ADD(3.1, 4.6);
    float a2 = SUB(6.2, 9.4);
    float a3 = MUT(3.0, 4.9);
    float a4 = DIV(6.1, 1.6);
    printf("%f,%f,%f,%f\n", a1, a2, a3, a4);

    int a = 1;
    int b = 3;
    int c = MAX(a, b++);
    printf("%d,%d,%d\n", a, b, c);

    float num = 9.1F;
    long lo = *(long *) &num;

    printf("%ld\n", lo);
}

/**
 *  输出错误内容
 **/
void err() {
    FILE *pf;
    pf = fopen("/data/doc/1.txt", "rb");
    if (pf == NULL) {
        perror("err number");
        fprintf(stderr, "fail to open file: %s\n", strerror(errno));
        exit(1);
    }
    fclose(pf);
}

int main(int argc, char *argv[]) {
    printf("hello world\n");
    printf("argc:%d,argv:", argc);
    for (int i = 0; i < argc; ++i) {
        printf("%s\t", argv[i]);
    }
    printf("\n");

    // def();
    // err();
    return 0;
}