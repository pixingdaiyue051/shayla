#include <stdio.h>

/**
 * 平方根倒数速算法
 * y = 1 / root(x)
 * y = x ^ (-0.5)
 * Fast Inverse Square Root
 * */
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

int main()
{
    float f = q_rsqrt(9.6597);
    printf("%.4f\n", f);
    return 0;
}