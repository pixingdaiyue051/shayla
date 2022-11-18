#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 指针
 */
void method_pointer()
{
    int i = 10;  // 声明一个int类型变量
    int *j = &i; // 声明一个int类型指针

    char g = 'c';
    char *z = &g;

    printf("%p,%d\n", &i, i);
    printf("%p,%d,%p\n", j, *j, &j); // 第二个地址是指针变量自身的地址
    printf("%p,%c\n", &g, g);
    printf("%p,%c,%p\n", z, *z, &z);
}

/**
 * 数组
 */
void method_arr()
{
    // 一维数组
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // 声明一个数组arr 同时arr会被编译器解释为指向该数组第一个元素的指针
    int s1 = sizeof(arr) / sizeof(int);         // 计算arr数组大小 10
    printf("%p,%p,%p\n", arr, &arr[0], &arr);
    printf("%d,%d\n", arr[0], *arr);
    int i;
    for (i = 0; i < s1; i++)
    {
        printf("%d,%d\n", arr[i], *(arr + i));
    }

    // 二维数组
    int arr1[][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}}; // 声明一个二维数组 但是内存上其实还是连续 同时arr1会被编译器解释为指向该数组第一个元素的指针
    int s2 = sizeof(arr1) / sizeof(int) / 3;           // 计算arr1数组大小 3
    printf("%p,%p,%p,%p\n", arr1, &arr1[0], &arr1[0][0], &arr1);
    printf("%d,%d,%d\n", *arr1[0], arr1[0][0], **arr1);
    printf("%d,%d\n", *arr1[1], arr1[1][0]);
    int ii, jj;
    int *zz;
    for (ii = 0; ii < s2; ii++)
    {
        zz = arr1[ii]; // 由于对arr1进行加减操作会在块内存之间运算 所以需要中间变量保存各块内存的
        for (jj = 0; jj < 3; jj++)
        {
            printf("%d,%d\n", arr1[ii][jj], *(zz + jj));
        }
    }

    char ss1[] = "abcd";                     // 等同于{'a', 'b', 'c', 'd', '\0'};
    int s3 = sizeof(ss1) / sizeof(char) - 1; // 计算ss1数组大小 4
    printf("%p,%p,%p\n", ss1, &ss1[0], &ss1);
    printf("%s,%c,%c\n", ss1, ss1[0], *ss1);
    int i1;
    for (i1 = 0; i1 < s3; i1++)
    {
        printf("%c,%c\n", ss1[i1], *(ss1 + i1));
    }

    char *ss2[] = {"abc", "def644", "ghia4"}; // 等同于 char ss2[][6] 但不建议
    int s4 = 3;
    printf("%p,%p,%p,%p\n", ss2, &ss2[0], &ss2[0][0], &ss2);
    printf("%c,%c,%c\n", *ss2[0], ss2[0][0], **ss2);
    int i2, i3;
    char *ch_tmp;
    int len_tmp;
    for (i2 = 0; i2 < s4; i2++)
    {
        ch_tmp = ss2[i2];
        len_tmp = strlen(ch_tmp);
        for (i3 = 0; i3 < len_tmp; i3++)
        {
            printf("%c,%c\n", ss2[i2][i3], *(ch_tmp + i3));
        }
    }
}

void method_str()
{
    char *ss1 = "ok";
    char *ss2 = "md";

    char *dest1 = malloc(1);
    char *r1 = strcpy(dest1, ss1);
    printf("%s,%s,%s\n", ss1, dest1, r1);
    free(dest1);

    char *r2 = strdup(ss2);
    printf("%s,%s\n", ss2, r2);
    free(r2);

    int r3 = strcmp(ss1, ss2);
    printf("%s%4s compared:%d\n", ss1, ss2, r3);
}

int main(int argc, const char *argv[])
{
    // method_pointer();
    // method_arr();
    method_str();
    return 0;
}