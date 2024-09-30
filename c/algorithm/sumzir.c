/**
 * 算法
 **/
#include <stdio.h>
#include <stdlib.h>

/**
 * 平方根倒数速算法
 * y = 1 / root(x)
 * y = x ^ (-0.5)
 * Fast Inverse Square Root
 **/
float q_rsqrt(float number)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    // 以整数方式读取
    i = *(long *)&y;
    // 神奇的步骤
    i = 0x5f3759df - (i >> 1);
    // 再以浮点方式读取
    y = *(float *)&i;
    // 牛顿迭代提高精度
    y = y * (threehalfs - (x2 * y * y));
    return y;
}

#define D(a) ((a) * (a))
#define C(a) ((a) * (a) * (a))

/**
 * 在15*17的矩阵内绘制爱心
 * (x^2+y^2-25)^3 - 25x^2y^3 < 0
 **/
void heart_drawer()
{
    // system("color 0c");
    int x, y, tmp;
    for (y = 9; y > -6; y--)
    {
        for (x = -8; x < 9; x++)
        {
            tmp = C(D(x) + D(y) - 25) < 25 * D(x) * C(y);
            putchar(tmp ? '*' : ' ');
        }
        putchar('\n');
    }
    // system("pause");
}

#include "linked_stack.h"

/**
 * 十进制 转换为其他进制2 8 16 需要借助链式栈
 **/
char *dec2transfer(int src, int reg)
{
    int d = src; // 不要污染原数据
    ls_t *stack = ls_init();
    while (d)
    {
        ls_push(stack, d % reg);
        d /= reg;
    }

    char *s = malloc(stack->size);
    int i = 0;
    ls_dt pm = 0;
    while (ls_pop(stack, &pm))
    {
        pm += 48;                    // 48是0的ascii
        pm = pm > 57 ? pm + 39 : pm; // 57是9的ascii 如果超9表示为16进制 需要再加39等于97(a的ascii)
        s[i++] = pm;
    }
    ls_free(stack);
    return s;
}

/**
 * 四则运算器 极简版
 **/
void caculator(const char *src)
{

}

int main()
{
    // float f = q_rsqrt(9.6597);
    // printf("%.4f\n", f);

    // heart_drawer();

    // int src = 126;
    // int reg = 16;
    // char *s = dec2transfer(src, reg);
    // printf("%d %d :%s", src, reg, s);

    caculator(argv[1]);
    return 0;
}