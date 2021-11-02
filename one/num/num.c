#include <stdio.h>

/**
 * 打印水仙花数
**/
void flower_num()
{
    //定义三位数num,个位数sd,十位数td,百位数hd
    int num, sd, td, hd;
    //循环所有三位数
    for (num = 100; num < 1000; num++)
    {
        //获取三位数字num百位上的数字
        hd = num / 100;
        //获取三位数字num十位上的数字
        td = (num - hd * 100) / 10;
        //获取三位数字num个位上的数字
        sd = num - hd * 100 - td * 10;
        int r = hd * hd * hd + td * td * td + sd * sd * sd;
        if (num == r)
        {
            printf("水仙花数字：%d\n", num);
        }
    }
}

/**
 * 倒序乘法表
 * */
void num9()
{
    // 定义相乘数字i,j以及结果result
    int i, j, result;

    for (i = 9; i >= 1; i--)
    {
        for (j = 1; i >= j; j++)
        {
            result = i * j;
            printf("%d*%d=%d\t", i, j, result);
        }
        printf("\n");
    }
}

/**
 * 输出正三角
 * */
void triangle()
{
    int i, j, k;
    for (i = 1; i < 5; i++)
    {
        /* 观察每行的空格数量，补全循环条件 */
        for (j = i; j < 5; j++)
        {
            printf(" "); //输出空格
        }
        /* 观察每行*号的数量，补全循环条件 */
        for (k = 0; k < 2 * i - 1; k++)
        {
            printf("*"); //每行输出的*号
        }
        printf("\n"); //每次循环换行
    }
}

/**
 * 输出质数
 * */
void prime_number()
{
    int m, n;
    for (m = 2; m <= 50; m++)
    {
        for (n = 2; n < m; n++)
        {
            if (m % n == 0) //什么条件下跳出当前循环
                break;      //这里应该退出当前循环了
        }
        if (m == n) //n循环结束后，如果m=n的话就输出m
            printf("%d\t", m);
    }
    printf("\n");
}

/**
 * 冒泡排序-正序
 * */
void bubble_sort_asc(int arr[], int arr_size)
{
    for (int i = arr_size - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/**
 * 冒泡排序-倒序
 * */
void bubble_sort_desc(int arr[], int arr_size)
{
    for (int i = arr_size - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void print_arr(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        if (i == arr_size - 1)
        {
            printf("%d\n", arr[i]);
        }
        else
        {
            printf("%d,", arr[i]);
        }
    }
}