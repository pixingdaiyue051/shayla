/**
 * 指向函数的指针
 * 主要用于传递函数回调 实现类似多态机制
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * 先定义指向函数指针类型 只要符合 int (int,int) 类型的函数都可以传入 method_fntptr
 */
typedef int (*comparebeyond)(int a, int b);

void method_fntptr(comparebeyond cb)
{
    printf("%d\n", cb(1, 0));
}

int cb(int c233, int vffh54)
{
    return 0;
}

int cberror0(int drr)
{
    return 1;
}

int cberror1(char drr)
{
    return 1;
}

char cberror2(int c233, int vffh54)
{
    return 1;
}

/**
 * 返回值是指针的函数
 * 仍然可以设计指向该函数的指针
 */
typedef char *(*compareptr)(char *s1, char *s2);

void method_fntptr1(compareptr cp)
{
    printf("%s\n", cp("da", "vds"));
}

char *cp0(char *vdfd, char *jllfs)
{
    return "0000";
}

char *cp1(char *ym54g, char *trhf)
{
    return "1111";
}

typedef struct DATA
{
    int a1;
    char *s1;
} Data;

/**
 * 函数内部改变形参 不会影响函数外部
 * 实参是类型 数据隔离
 **/
void fnt(int arg0, char arg1[], Data data)
{
    puts("----fnt------");
    arg0 = 18; // 不改变外部数据
    // arg1[0] = 'd'; // 改变外部数据
    arg1 = "43ddf"; // 不改变外部数据 实际上arg1指向了一个新的字符串
    data.a1 = 111; // 不改变外部数据
    data.s1 = "56fg"; // 不改变外部数据
    printf("arg0 %d\n", arg0);
    printf("arg1 %s\n", arg1);
    printf("data %d %s\n", data.a1, data.s1);
}


/**
 * 函数内部改变形参 不会影响函数外部
 * 实参是指针 数据共享
 **/
void fnt1(int *arg0, char *arg1, Data *data)
{
    puts("----fnt1------");
    // *arg0 = 18; // 改变外部数据
    // *arg1 = "43ddf"; // 改变外部数据 不要这样写
    // data->a1 = 111; // 改变外部数据
    // data->s1 = "56fg"; // 改变外部数据

    arg0 = malloc(sizeof(int)); // 不改变外部数据 实际上arg0指向了一个新的数字
    arg1 = "43ddf"; // 不改变外部数据 实际上arg1指向了一个新的字符串 --arg1[0] = 'd';segment fault Bad permissions for mapped region at address
    data = malloc(sizeof(Data)); // 不改变外部数据 实际上data指向了一个新的结构体
    data->a1 = 23332;
    data->s1 = "0x6984.524f";
    printf("arg0 %d\n", *arg0);
    printf("arg1 %s\n", arg1);
    printf("data %d %s\n", data->a1, data->s1);
}

int main()
{
    // method_fntptr(cb);
    // method_fntptr(cberror0);
    // method_fntptr(cberror1);
    // method_fntptr(cberror2);
    // method_fntptr(NULL);
    // method_fntptr1(cp0);
    // method_fntptr1(cp1);

    int arg0 = 9;
    char arg1[] = "fssg";
    Data data = {.a1 = 2, .s1 = "3.14f"};
    // fnt(arg0, arg1, data);
    fnt1(&arg0, arg1, &data);
    printf("arg0 %d\n", arg0);
    printf("arg1 %s\n", arg1);
    printf("data %d %s\n", data.a1, data.s1);

    return 0;
}